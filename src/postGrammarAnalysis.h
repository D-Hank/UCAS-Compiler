#pragma once

#include <vector>
#include <map>
#include <unordered_map>

#define COMPILE_ERROR 1
#define MAIN_FUNC_NAME "main"

typedef enum val_type
{
    void_type,
    int_type,
    float_type,
    double_type,
    bool_type,
    max_val_type,
} val_type_t;

typedef enum stmt_type
{
    assign_stmt = 0,
    exp_stmt = 1,
    block_stmt = 2,
    if_stmt = 3,
    while_stmt = 4,
    break_stmt = 5,
    continue_stmt = 6,
    return_stmt = 7,
} stmt_type_t;

class PostGrammarAnalysis
{
public:
    std::map <std::string, val_type_t> str_to_val_type {
        {"void", void_type},
        {"int", int_type},
        {"float", float_type},
        {"double", double_type},
        {"bool", bool_type},
    };

    std::map <val_type_t, const char *> val_type_to_str {
        {void_type, "void"},
        {int_type, "int"},
        {float_type, "float"},
        {double_type, "double"},
        {bool_type, "bool"},
    };

    std::map<val_type_t, size_t> type_to_size {
        {void_type, 8},
        {int_type, 4},
        {float_type, 4},
        {double_type, 8},
        {bool_type, 1},
    };

};

extern PostGrammarAnalysis post_grammar_stage;
