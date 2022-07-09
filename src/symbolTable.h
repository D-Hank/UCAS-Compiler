#pragma once

#include <vector>
#include <map>
#include <unordered_map>

#include "postGrammarAnalysis.h"

// Scope tree for variable
typedef struct scope_node
{
    scope_node *father;
    std::vector<scope_node *> children;
} scope_node_t;

typedef struct name_scope_pair
{
    std::string var_name;
    scope_node_t *scope_ptr;

    // overload for compare operator to compare two pairs
    bool operator==(const name_scope_pair &pair) const
    {
        return (pair.scope_ptr == scope_ptr) && (pair.var_name == var_name);
    }
} name_in_scope;

// override for hash function
// will not create a new object, but return its hash value
struct pair_hash_func
{
    size_t operator()(const name_scope_pair &pair) const
    {
        return (std::hash<std::string>()(pair.var_name)) ^ (std::hash<scope_node_t *>()(pair.scope_ptr) << 1);
    }
};

typedef struct func_fparam_item
{
    std::string fparam_name; // necessary?
    val_type_t fparam_type;
    int which_fparam; // order
    bool is_array;

    // overload for compare operator to guarantee the order of fparams
    bool operator<(func_fparam_item const &item) const
    {
        return which_fparam < item.which_fparam;
    }
} func_fparam_item_t;

typedef struct func_symbol_item
{
    std::string func_name;
    val_type_t ret_type;
    std::map<std::string, func_fparam_item_t> fparam_list;

    std::string which_label;
} func_symbol_item_t;

typedef struct var_symbol_item
{
    std::string var_name;
    val_type_t var_type;
    bool is_array;
    bool is_const;
    size_t num_items;
    scope_node_t *scope;
} var_symbol_item_t;

class SymbolTable
{
public:
    scope_node_t *scope_root;

    std::unordered_map <std::string, func_symbol_item_t> func_symbol_table;
    std::unordered_map <name_in_scope, var_symbol_item_t, pair_hash_func> var_symbol_table;

    std::unordered_map <name_in_scope, var_symbol_item_t, pair_hash_func>::iterator findVarInTab(std::string var, scope_node_t * current_scope) {
        auto end = var_symbol_table.end();
        while (current_scope != NULL) {
            auto iter = var_symbol_table.find((name_in_scope){var, current_scope});
            if (iter != end) {
                return iter;
            }

            current_scope = current_scope -> father;
        }

        return end;
    }

};
extern SymbolTable symbol_table;
