#include "semanticAnalysis.h"
#include "postGrammarAnalysis.h"

void SemanticAnalysis::enterCompUnit(CACTParser::CompUnitContext * ctx)
{
    // Initialization
    symbol_table.scope_root = new scope_node_t;
    (symbol_table.scope_root) -> father = nullptr;
    current_scope = (symbol_table.scope_root);
    // Note: scope for main should be created when defining main function

    // Add built-in functions into symtab
    addBuiltInFunc();
}

void SemanticAnalysis::addFunc(std::string func_name, int argc, val_type_t arg_type, val_type_t ret_type, std::string arg_name)
{
    std::map <std::string, func_fparam_item_t> fparam_list;
    if(argc == 1){
        fparam_list[arg_name] = (func_fparam_item_t){arg_name, arg_type, 0, false};
    }
    (symbol_table.func_symbol_table)[func_name] = (func_symbol_item_t){func_name, ret_type, fparam_list};
}

void SemanticAnalysis::addBuiltInFunc()
{
    addFunc("print_int", 1, int_type, void_type);
    addFunc("print_float", 1, float_type, void_type);
    addFunc("print_double", 1, double_type, void_type);
    addFunc("print_bool", 1, bool_type, void_type);
    addFunc("get_int", 0, void_type, int_type);
    addFunc("get_float", 0, void_type, float_type);
    addFunc("get_double", 0, void_type, double_type);
}

void SemanticAnalysis::checkMainFunc()
{
    // Check if there is MAIN function
    auto main_sym_item_iter = (symbol_table.func_symbol_table).find(MAIN_FUNC_NAME);
    if(main_sym_item_iter == (symbol_table.func_symbol_table).end()){
        std::cout << "Missing main function." << std::endl;
        exit(COMPILE_ERROR);
    }

    // Check type for main
    auto main_sym_item = main_sym_item_iter -> second; // first is key, second is value
    val_type_t ret_type = main_sym_item.ret_type;
    if(ret_type != int_type){
        std::cout << "Wrong type for main, should be defined as int, but get " << ret_type << std::endl;
        exit(COMPILE_ERROR);
    }

    // Check fparam list for main
    size_t num_args = main_sym_item.fparam_list.size();
    if(num_args != 0){
        std::cout << "No arguments is supported for main function, but get " << num_args << " argument(s)." << std::endl;
        exit(COMPILE_ERROR);
    }
}

void SemanticAnalysis::exitCompUnit(CACTParser::CompUnitContext * ctx)
{
    checkMainFunc();
}

void SemanticAnalysis::exitConstDecl(CACTParser::ConstDeclContext * ctx)
{
    // Fetch declared type
    val_type_t btype = (val_type_t)(ctx -> bType() -> btype_val_type);
    ctx -> const_decl_val_type = (int)btype;

    // Check declared type and actual type for every const
    // Use iterator to traverse
    val_type_t actual_type;
    std::string id;
    bool is_array;
    size_t num_items;
    for(const auto & const_def: ctx -> constDef()){
        actual_type = (val_type_t)(const_def -> def_val_type);
        id = const_def -> id_name;
        is_array = const_def -> is_array;
        num_items = const_def -> num_items;
        // If initialized but not match
        if(actual_type != void_type && actual_type != btype){
            std::cout << "Type mismatched for " << id << ", declared: " << btype << ", but get: " << const_def -> def_val_type << std::endl;
            exit(COMPILE_ERROR);
        }
        std::cout << "const_type: " << btype << std::endl;
        std::cout << "const_name: " << id << std::endl;

        // Notice: please add a new entry into the symbol table!
        // TODO: Add your CODE here
        // Use btype in such entry
        // Set is_const=true
        /*zty*/
        (symbol_table.var_symbol_table)[(name_in_scope){id,current_scope}] = (var_symbol_item_t){id, btype, is_array, true, num_items, current_scope};
    }
}

void SemanticAnalysis::exitBType(CACTParser::BTypeContext * ctx)
{
    ctx -> btype_val_type = (int)((post_grammar_stage.str_to_val_type)[ctx -> getText()]);
    //std::cout << "type: " << ctx -> btype_val_type << std::endl;
}

// Used for VarDef_empty/init and ConstDef_empty/init
// Argument default value: is_array_right_side=true, num_items_right_side=0, type_right_side=0
template <typename T_ctx>
void SemanticAnalysis::exitConstAndVarDef(T_ctx &ctx, bool is_array_right_side, size_t num_items_right_side, int type_right_side)
{
    std::string id = ctx -> Ident() -> getText();
    // Notice: please check duplicated name!!!
    // TODO: Add your CODE here
    auto const_and_var_iter = (symbol_table.var_symbol_table).find((name_in_scope){id, current_scope});
    if(const_and_var_iter != (symbol_table.var_symbol_table).end()){
        std::cout << "Duplicated " << ((const_and_var_iter -> second).is_const == true) ? "const" : "variable";
        std::cout << " name: " << (const_and_var_iter -> second).var_name << std::endl;
        exit(COMPILE_ERROR);
    }

    // Pass num_items
    size_t num_items;
    bool is_array;
    if((ctx -> IntConst()) == nullptr){ // Set item=0 for a single variable
        is_array = false;
        num_items = 1;
    }else{
        is_array = true;
        num_items = atol((ctx -> IntConst() -> getText()).c_str());
        //std::cout << "Array items: " << num_items << std::endl;
    }

    // type_right_side=0 when we need to initialize
    if(type_right_side != (int)(void_type)){
        // Check for is_array
        if(is_array != is_array_right_side){
            std::cout << "Type mismatched when initializing " << id << ", with array and a basic type." << std::endl;
            exit(COMPILE_ERROR);
        }

        // Check num_items
        /*if(num_items != num_items_right_side){
            std::cout << "Number of elements mismatched for " << id << std::endl;
            exit(COMPILE_ERROR);
        }*/
    }

    // Pass type attributes upward
    ctx -> id_name = id;
    ctx -> def_val_type = type_right_side;
    ctx -> is_array = is_array;
    ctx -> num_items = num_items;
}

template <typename T_ctx>
void SemanticAnalysis::exitConstAndVarDefInit(T_ctx &ctx)
{
    size_t num_items = ctx -> constInitVal() -> num_items;
    bool is_array = ctx -> constInitVal() -> is_array;
    int type = ctx -> constInitVal() -> init_val_type;
    exitConstAndVarDef(ctx, is_array, num_items, type);
}

void SemanticAnalysis::exitConstDef_empty(CACTParser::ConstDef_emptyContext * ctx)
{
    // No need to init, so right_side_type=void
    exitConstAndVarDef(ctx);
}

void SemanticAnalysis::exitConstDef_init(CACTParser::ConstDef_initContext * ctx)
{
    exitConstAndVarDefInit(ctx);
}

void SemanticAnalysis::exitConstExp_single(CACTParser::ConstExp_singleContext * ctx)
{
    ctx -> init_val_type = ctx -> constExp() -> const_type;
    ctx -> num_items = 1;
    ctx -> is_array = false;
}

void SemanticAnalysis::exitConstExp_array(CACTParser::ConstExp_arrayContext * ctx)
{
    size_t num_items = (ctx -> constExp()).size();
    if(num_items != 0){
        int item_type = (ctx -> constExp())[0] -> const_type;
        for(size_t i = 1; i < num_items; i++){
            if(((ctx -> constExp())[i]) -> const_type != item_type){
                std::cout << "Type mismatched in array initialization, expected: " << item_type << std::endl;
                exit(COMPILE_ERROR);
            }
        }
        ctx -> init_val_type = item_type;
    }else{
        ctx -> init_val_type = (int)void_type;
    }

    ctx -> num_items = num_items;
    ctx -> is_array = true;
}

void SemanticAnalysis::exitVarDecl(CACTParser::VarDeclContext * ctx)
{
    // Fetch declared type
    val_type_t btype = (val_type_t)(ctx -> bType() -> btype_val_type);
    ctx -> var_decl_val_type = (int)btype;
    auto var_list = ctx -> varDef();
    size_t num_vars = var_list.size();

    // Check declared type and actual type for every variable
    // Use array to traverse
    val_type_t actual_type;
    std::string id;
    bool is_array;
    size_t num_items;
    for(size_t i = 0; i < num_vars; i ++){
        actual_type = (val_type_t)(var_list[i] -> def_val_type);
        id = var_list[i] -> id_name;
        is_array = var_list[i] -> is_array;
        num_items = var_list[i] -> num_items;        
        // If initialized but not match
        if(actual_type != void_type && actual_type != btype){
            std::cout << "Type mismatched for " << id << ", declared: " << btype << ", but get: " << var_list[i] -> def_val_type << std::endl;
            exit(COMPILE_ERROR);
        }
        std::cout << "var_type: " << btype << std::endl;
        std::cout << "var_name: " << id << std::endl;

        // Notice: please add a new entry into the symbol table!
        // TODO: Add your CODE here
        // Use btype in such entry
        // Set is_const=false
        /*zty*/
        (symbol_table.var_symbol_table)[(name_in_scope){id,current_scope}] = (var_symbol_item_t){id, btype, is_array, false, num_items, current_scope};
        
    }
}

void SemanticAnalysis::exitVarDef_empty(CACTParser::VarDef_emptyContext * ctx)
{
    exitConstAndVarDef(ctx);
}

void SemanticAnalysis::exitVarDef_init(CACTParser::VarDef_initContext * ctx)
{
    exitConstAndVarDefInit(ctx);
}

void SemanticAnalysis::enterFuncDef(CACTParser::FuncDefContext * ctx)
{
    // Allow child nodes to reference name
    std::string * new_name = new std::string;
    ctx -> funcHeader() -> name_to_fill = new_name;
    ctx -> block() -> which_func = new_name;
    // Pass inherited attributes
    ctx -> block() -> allow_return = true;
    ctx -> block() -> from_func = true;
}

void SemanticAnalysis::exitFuncHeader(CACTParser::FuncHeaderContext * ctx)
{
    std::string func_name = ctx -> Ident() -> getText();
    *(ctx -> name_to_fill) = func_name;

    // Check duplicated name
    if((symbol_table.func_symbol_table).find(func_name) != (symbol_table.func_symbol_table).end()){
        std::cout << "Duplicated function name: " << func_name << std::endl;
        exit(COMPILE_ERROR);
    }

    // Read arg list
    auto fparams_defined = ctx -> funcFParam();
    size_t num_params = fparams_defined.size();
    val_type_t fparam_type;
    std::string fparam_name;
    bool fparam_is_array;
    std::map <std::string, func_fparam_item_t> fparam_list;
    for(size_t i = 0; i < num_params; i ++){
        fparam_name = fparams_defined[i] -> arg_name;
        // Check parameters' name, duplicated names are not allowed
        if(fparam_list.find(fparam_name) != fparam_list.end()){
            std::cout << "Duplicated argument: " << fparam_name << " for function " << func_name << std::endl;
            exit(COMPILE_ERROR);
        }

        fparam_type = (val_type_t)(fparams_defined[i] -> arg_type);
        fparam_is_array = fparams_defined[i] -> is_array;

        // Add an fparam into the list
        fparam_list[fparam_name] = (func_fparam_item_t){fparam_name, fparam_type, i, fparam_is_array};
    }

    // Add a new entry into the symtab
    val_type_t ret_type = (val_type_t)(ctx -> funcType() -> func_type);
    std::cout << "func_type: " << ret_type << std::endl;
    std::cout << "func_name: " << func_name << std::endl;
    (symbol_table.func_symbol_table)[func_name] = (func_symbol_item_t){func_name, ret_type, fparam_list};
}

void SemanticAnalysis::exitFuncDef(CACTParser::FuncDefContext * ctx)
{
    std::string func_name = *(ctx -> funcHeader() -> name_to_fill);

    // Check RETURN statement in the function body
    val_type_t ret_type = (symbol_table.func_symbol_table)[func_name].ret_type;
    val_type_t block_ret_type = (val_type_t)(ctx -> block() -> actual_return_type);
    if((ctx -> block() -> actual_has_return) == false){
        // No RETURN on the right side
        if(ret_type != void_type){
            std::cout << "Warning: there is no return statement in function " << func_name << ", the result may be unexpected" << std::endl;
        }
    }else{
        if(ret_type != block_ret_type){
            std::cout << "Type of return in the body is " << block_ret_type;
            std::cout << ", but " << ret_type << " is declared." << std::endl;
            exit(COMPILE_ERROR);
        }
    }
}

void SemanticAnalysis::exitFuncType(CACTParser::FuncTypeContext * ctx)
{
    std::string func_type = ctx -> getText();
    ctx -> func_type = (int)((post_grammar_stage.str_to_val_type)[ctx -> getText()]);
}

void SemanticAnalysis::exitFuncFParam_single(CACTParser::FuncFParam_singleContext * ctx)
{
    ctx -> arg_name = ctx -> Ident() -> getText();
    ctx -> arg_type = ctx -> bType() -> btype_val_type;
    ctx -> is_array = false;
}

void SemanticAnalysis::exitFuncFParam_array(CACTParser::FuncFParam_arrayContext * ctx)
{
    ctx -> arg_name = ctx -> Ident() -> getText();
    ctx -> arg_type = ctx -> bType() -> btype_val_type;
    ctx -> is_array = true;
}

void SemanticAnalysis::enterBlock(CACTParser::BlockContext * ctx)
{
    // Add a new scope
    scope_node_t * new_scope = new scope_node_t;
    new_scope -> father = current_scope;
    // index in this block's father scope
    ctx -> index_in_father = (current_scope -> children).size();
    (current_scope -> children).push_back(new_scope);
    current_scope = new_scope;

    // Check if this block is from function
    if((ctx -> from_func == true)){
        // Copy variables from fparam_list
        auto func_fparam_list = (symbol_table.func_symbol_table)[*(ctx -> which_func)].fparam_list;
        for(auto fparam_iter = func_fparam_list.begin(); fparam_iter != func_fparam_list.end(); fparam_iter ++){
            auto fparam_item = fparam_iter -> second;
            (symbol_table.var_symbol_table)[(name_in_scope){fparam_item.fparam_name, new_scope}] = (var_symbol_item_t){
                fparam_item.fparam_name,
                fparam_item.fparam_type,
                fparam_item.is_array,
                // `const` keyword is not used in funcDef
                false,
                0,
                new_scope,
            };
        }
    }

    auto block_items = ctx -> blockItem();
    size_t num_items = block_items.size();
    bool block_allow_break = ctx -> allow_break;
    bool block_allow_continue = ctx -> allow_continue;
    bool block_allow_return = ctx -> allow_return;
    for(size_t i = 0; i < num_items; i ++){
        // Pass attributes downward
        block_items[i] -> allow_break = block_allow_break;
        block_items[i] -> allow_continue = block_allow_continue;
        block_items[i] -> allow_return = block_allow_return;
    }
}

void SemanticAnalysis::exitBlock(CACTParser::BlockContext * ctx)
{
    // Check each item
    auto block_items = ctx -> blockItem();
    size_t num_items = block_items.size();
    bool actual_has_return = false;
    int actual_return_type = (int)void_type;

    // Search for an item that has return
    for(size_t i = 0; i < num_items; i ++){
        if((block_items[i] -> actual_has_return) == true){
            // There are such items
            actual_has_return = true;
            actual_return_type = block_items[i] -> actual_return_type;
            // Continue to check rest items
            for(size_t j = i + 1; j < num_items; j ++){
                // Has return but type not matched
                if((block_items[j] -> actual_has_return == true) && (block_items[j] -> actual_return_type != actual_return_type)){
                    std::cout << "Type of return not matched in this block, expecting ";
                    std::cout << actual_return_type << ", but encountered " << block_items[j] -> actual_return_type << std::endl;
                    exit(COMPILE_ERROR);
                }
            }
            break;
        }
    }

    // Check finished or there is no suck item
    ctx -> actual_has_return = actual_has_return;
    ctx -> actual_return_type = actual_return_type;

    // Recover the current scope
    current_scope = current_scope -> father;
}

void SemanticAnalysis::enterBlockItem(CACTParser::BlockItemContext * ctx)
{
    auto ctx_stmt = ctx -> stmt();
    // If this item is stmt
    if(ctx_stmt != nullptr){
        ctx_stmt -> allow_break = ctx -> allow_break;
        ctx_stmt -> allow_continue = ctx -> allow_continue;
        ctx_stmt -> allow_return = ctx -> allow_return;
    }
}

void SemanticAnalysis::exitBlockItem(CACTParser::BlockItemContext * ctx)
{
    auto ctx_stmt = ctx -> stmt();
    // If this item is stmt
    if(ctx_stmt != nullptr){
        ctx -> actual_has_return = ctx_stmt -> actual_has_return;
        ctx -> actual_return_type = ctx_stmt -> actual_return_type;
    }
    // default: actual_has_return=false
}

void SemanticAnalysis::exitStmt_assign(CACTParser::Stmt_assignContext * ctx)
{
    // Notice: please assign exp_val_type when doing check for assign statement!!!
    ctx -> stmt_type = (int)assign_stmt;
    ctx -> stmt_val_type = ctx -> exp() -> exp_val_type;
    // Check const for left side 
    if(ctx-> lVal() -> is_const){
        std::cout << "In an assign statement, const can't be placed at left" << std::endl;
        exit(COMPILE_ERROR);
    }

    // Check is array
    bool is_array_1 = ctx -> lVal() -> is_array;
    bool is_array_2 = ctx -> exp() -> is_array;
    if(is_array_1 != is_array_2){
        std::cout << "In an assign statement, array type mismatched" << std::endl;
        exit(COMPILE_ERROR);
    }

    // Check type
    int type_1 = ctx -> lVal() -> lval_type;
    int type_2 = ctx -> exp() -> exp_val_type;
    if(type_1 != type_2){
        std::cout << "In a assign statment, type mismatched" << std::endl;
        exit(COMPILE_ERROR);
    }

    // Check items
    size_t num_1 = ctx -> lVal() -> num_items;
    size_t num_2 = ctx -> exp() -> num_items;
    if(is_array_1 == true && (num_1 != num_2)){
        std::cout << "In a assign statment, length mismatched" << std::endl;
        exit(COMPILE_ERROR);
    }
}

void SemanticAnalysis::exitStmt_exp(CACTParser::Stmt_expContext * ctx)
{
    // Check for condition
    ctx -> stmt_type = (int)exp_stmt;
    if((ctx -> exp()) != nullptr){
        ctx -> stmt_val_type = ctx -> exp() -> exp_val_type;
    }else{
        ctx -> stmt_val_type = (int)void_type;
    }
}

void SemanticAnalysis::enterStmt_block(CACTParser::Stmt_blockContext * ctx)
{
    auto ctx_block = ctx -> block();
    ctx_block -> allow_break = ctx -> allow_break;
    ctx_block -> allow_continue = ctx -> allow_continue;
    ctx_block -> allow_return = ctx -> allow_return;
}

void SemanticAnalysis::exitStmt_block(CACTParser::Stmt_blockContext * ctx)
{
    auto ctx_block = ctx -> block();
    ctx -> actual_has_return = ctx_block -> actual_has_return;
    ctx -> actual_return_type = ctx_block -> actual_return_type;
}

void SemanticAnalysis::enterStmt_if(CACTParser::Stmt_ifContext * ctx)
{
    auto ctx_stmt = ctx -> stmt();
    ctx_stmt[0] -> allow_break = ctx -> allow_break;
    ctx_stmt[0] -> allow_continue = ctx -> allow_continue;
    ctx_stmt[0] -> allow_return = ctx -> allow_return;

    if(ctx_stmt.size() > 1){
        ctx_stmt[1] -> allow_break = ctx -> allow_break;
        ctx_stmt[1] -> allow_continue = ctx -> allow_continue;
        ctx_stmt[1] -> allow_return = ctx -> allow_return;
    }
}

void SemanticAnalysis::exitStmt_if(CACTParser::Stmt_ifContext * ctx)
{
    if ((ctx -> stmt()).size() <= 1) {
        auto ctx_stmt = (ctx -> stmt())[0];
        ctx -> actual_has_return = ctx_stmt -> actual_has_return;
        ctx -> actual_return_type = ctx_stmt -> actual_return_type;
        return;
    }
    auto ctx_stmt_1 = (ctx -> stmt())[0];
    auto ctx_stmt_2 = (ctx -> stmt())[1];

    bool has_return_1 = ctx_stmt_1 -> actual_has_return;
    bool has_return_2 = ctx_stmt_2 -> actual_has_return;
    int return_type_1 = ctx_stmt_1 -> actual_return_type;
    int return_type_2 = ctx_stmt_2 -> actual_return_type;

    // If both have return
    if((has_return_1 == true) && (has_return_2 == true)){
        // but not matched
        if(return_type_1 != return_type_2){
            std::cout << "In if statement, type of return in two branches not matched, ";
            std::cout << return_type_1 << " and " << return_type_2 << std::endl;
            exit(COMPILE_ERROR);
        }

        // matched
        ctx -> actual_has_return = true;
        ctx -> actual_return_type = return_type_1;

    }else if(has_return_1 == true){
        ctx -> actual_has_return = true;
        ctx -> actual_return_type = return_type_1;
        std::cout << "Warning: In if statement, type of return in the second branch is unpredictable." << std::endl;
    }else if(has_return_2 == true){
        ctx -> actual_has_return = true;
        ctx -> actual_return_type = return_type_2;
        std::cout << "Warning: In if statement, type of return in the first branch is unpredictable." << std::endl;
    }else{
        ctx -> actual_has_return = false;
        ctx -> actual_return_type = (int)void_type;
    }
}

void SemanticAnalysis::enterStmt_while(CACTParser::Stmt_whileContext * ctx)
{
    auto ctx_stmt = ctx -> stmt();
    ctx_stmt -> allow_break = true;
    ctx_stmt -> allow_continue = true;
    ctx_stmt -> allow_return = ctx -> allow_return;
}

void SemanticAnalysis::exitStmt_while(CACTParser::Stmt_whileContext * ctx)
{
    ctx -> actual_has_return = ctx -> stmt() -> actual_has_return;
    ctx -> actual_return_type = ctx -> stmt() -> actual_return_type;
}

void SemanticAnalysis::enterStmt_break(CACTParser::Stmt_breakContext * ctx)
{
    // Check break is allowed to be used here
    if((ctx -> allow_break) == false){
        std::cout << "Break is not allowed in this block." << std::endl;
        exit(COMPILE_ERROR);
    }
}

void SemanticAnalysis::enterStmt_continue(CACTParser::Stmt_continueContext * ctx)
{
    if((ctx -> allow_continue) == false){
        std::cout << "Continue is not allowed in this block." << std::endl;
        exit(COMPILE_ERROR);
    }
}

void SemanticAnalysis::enterStmt_return(CACTParser::Stmt_returnContext * ctx){
    if((ctx -> allow_return) == false){
        std::cout << "Return is not allowed in this block." << std::endl;
        exit(COMPILE_ERROR);
    }
}

void SemanticAnalysis::exitStmt_return(CACTParser::Stmt_returnContext * ctx)
{
    ctx -> actual_has_return = true;
    if((ctx -> exp()) != nullptr){
        ctx -> actual_return_type = ctx -> exp() -> exp_val_type;
    }else{
        ctx -> actual_return_type = (int)void_type;
    }
}

void SemanticAnalysis::exitExp_add(CACTParser::Exp_addContext * ctx)
{
    ctx -> exp_val_type = ctx -> addExp() -> add_exp_val_type;
    ctx -> is_const = ctx -> addExp() -> is_const;
    ctx -> is_array = ctx -> addExp() -> is_array;
    ctx -> is_from_symtab = ctx -> addExp() -> is_from_symtab;   
    ctx -> num_items = ctx -> addExp() -> num_items;
}

void SemanticAnalysis::exitExp_bool(CACTParser::Exp_boolContext * ctx)
{
    ctx -> exp_val_type = (int)bool_type;
    ctx -> is_const = true;
    ctx -> is_array = false;
    ctx -> is_from_symtab = false;
    ctx -> num_items = 1;
}

void SemanticAnalysis::exitCond(CACTParser::CondContext * ctx)
{
    bool is_array = ctx -> lOrExp() -> is_array;
    int type = ctx -> lOrExp() -> lOr_exp_val_type;
    if(is_array == true || type != (int)bool_type){
        std::cout << "Wrong type in cond" << std::endl;
        exit(COMPILE_ERROR);
    }
}

void SemanticAnalysis::exitLVal(CACTParser::LValContext * ctx)
{
    // Check if is from array
    bool lval_from_array = ((ctx -> exp()) != nullptr);
    // Notice: exp is dynamic, so we may not have enough info about it
    std::string id = ctx -> Ident() -> getText();
    // Check from current scope
    auto scope_temp = current_scope;
    var_symbol_item_t *symtab_item = nullptr;
    while(scope_temp != nullptr){
        auto const_and_var_iter = (symbol_table.var_symbol_table).find((name_in_scope){id, scope_temp});
        if(const_and_var_iter != (symbol_table.var_symbol_table).end()){
            symtab_item = &(const_and_var_iter -> second);
            break;
        }
        scope_temp = scope_temp -> father;
    }

    // Var not found
    if(symtab_item == nullptr){
        std::cout << "Variable or const " << id << " not defined before referenced" << std::endl;
        exit(COMPILE_ERROR);
    }

    ctx -> is_array = ((ctx -> exp()) == nullptr) ? (symtab_item -> is_array) : false;
    ctx -> num_items = symtab_item -> num_items;
    ctx -> lval_type = symtab_item -> var_type;
    ctx -> is_const = false;
    ctx -> is_from_symtab = true;
}

void SemanticAnalysis::exitPrimaryExp_exp(CACTParser::PrimaryExp_expContext * ctx)
{
    ctx -> primary_exp_val_type = ctx -> exp() -> exp_val_type;
    ctx -> is_const = ctx -> exp() -> is_const;
    ctx -> is_array = ctx -> exp() -> is_array;
    ctx -> is_from_symtab = ctx -> exp() -> is_from_symtab;
    ctx -> num_items = ctx -> exp() -> num_items;
}

void SemanticAnalysis::exitPrimaryExp_lval(CACTParser::PrimaryExp_lvalContext * ctx)
{
    ctx -> primary_exp_val_type = ctx -> lVal() -> lval_type;
    ctx -> is_const = ctx -> lVal() -> is_const;
    ctx -> is_array = ctx -> lVal() -> is_array;
    ctx -> is_from_symtab = ctx -> lVal() -> is_from_symtab;
    ctx -> num_items = ctx -> lVal() -> num_items;
}

void SemanticAnalysis::exitPrimaryExp_num(CACTParser::PrimaryExp_numContext * ctx)
{
    ctx -> primary_exp_val_type = ctx -> number() -> number_type;
    ctx -> is_const = true;
    ctx -> is_array = false;
    ctx -> is_from_symtab = false;
    ctx -> num_items = 1;
}

void SemanticAnalysis::exitUnaryExp_primary(CACTParser::UnaryExp_primaryContext * ctx)
{
    ctx -> unary_exp_val_type = ctx -> primaryExp() -> primary_exp_val_type;
    ctx -> is_const = ctx -> primaryExp() -> is_const;
    ctx -> is_array = ctx -> primaryExp() -> is_array;
    ctx -> is_from_symtab = ctx -> primaryExp() -> is_from_symtab;
    ctx -> num_items = ctx -> primaryExp() -> num_items;
}

void SemanticAnalysis::exitUnaryExp_call(CACTParser::UnaryExp_callContext * ctx)
{
    // Notice: please check the symbol table for identifiers
    std::string func_name = ctx -> Ident() -> getText();
    auto func_iter = (symbol_table.func_symbol_table).find(func_name);

    // Check undefined function
    if(func_iter == (symbol_table.func_symbol_table).end()){
        std::cout << "Undefined function name: " << func_name << std::endl;
        exit(COMPILE_ERROR);
    }

    // Check function parameter
    auto param_list = (func_iter -> second).fparam_list;

    if (ctx -> funcRParams()){ 
        // Check if the number of parameters matches
        if (param_list.size() != ctx -> funcRParams() -> exp().size()){
            std::cout << "Number of parameters mismatched for function name: " << func_name << std::endl;
            exit(COMPILE_ERROR);
        }
        auto exp_list = ctx -> funcRParams() -> exp();
        size_t num_exps = exp_list.size();
        auto fparam_iter = param_list.begin();
        
        // Check if the types of parameters matches
        for(size_t i = 0; i < num_exps; i++, fparam_iter++){
            if (exp_list[i] -> exp_val_type != fparam_iter -> second.fparam_type || exp_list[i] -> is_array != fparam_iter -> second.is_array){
                std::cout << "Type of parameters mismatched for function name: " << func_name << std::endl;
                exit(COMPILE_ERROR);
            }
            if (exp_list[i] -> is_const && exp_list[i] -> is_from_symtab){
                std::cout << "Const can't be used for parameter in function name " << func_name << std::endl;
                exit(COMPILE_ERROR);
            }
        }
    }else{ 
        // the function has no parameter
        if(param_list.empty() == false){
            std::cout << "Number of parameters mismatched for function name: " << func_name << std::endl;
            exit(COMPILE_ERROR);
        }
    }

    ctx -> unary_exp_val_type = (func_iter -> second).ret_type;
    ctx -> is_const = false;
    ctx -> is_array = false;
    ctx -> is_from_symtab = false;
    ctx -> num_items = (func_iter -> second).ret_type == 0 ? 0 : 1;
}

void SemanticAnalysis::exitUnaryExp_uop(CACTParser::UnaryExp_uopContext * ctx)
{
    // Type check
    val_type_t uexp_val_type = (val_type_t)(ctx -> unaryExp() -> unary_exp_val_type);
    std::string oprt = ctx -> unaryOp() -> getText();
    bool uis_array = ctx -> unaryExp() -> is_array;
    int unum_items = ctx -> unaryExp() -> num_items;
    std::cout << "OP: " << oprt << std::endl;
    if((oprt == "+" || oprt == "-") && (uexp_val_type != int_type) && (uexp_val_type != float_type) && (uexp_val_type != double_type)){
        std::cout << "Operator: " << oprt << " can only be used with int, float or double." << std::endl;
        exit(COMPILE_ERROR);
    }
    if((oprt == "!") && (uexp_val_type != bool_type || uis_array == true)){
        std::cout << "Operator: " << oprt << " can only be used with bool." << std::endl;
        exit(COMPILE_ERROR);
    }

    // Pass type
    ctx -> unary_exp_val_type = uexp_val_type;
    ctx -> is_const = ctx -> unaryExp() -> is_const;
    ctx -> is_array = uis_array;
    ctx -> is_from_symtab = ctx -> unaryExp() -> is_from_symtab;
    ctx -> num_items = unum_items;
}

void SemanticAnalysis::exitMulExp_unary(CACTParser::MulExp_unaryContext * ctx)
{
    ctx -> mul_exp_val_type = ctx -> unaryExp() -> unary_exp_val_type;
    ctx -> is_const = ctx -> unaryExp() -> is_const;
    ctx -> is_array = ctx ->unaryExp() -> is_array;
    ctx -> is_from_symtab = ctx -> unaryExp() -> is_from_symtab;
    ctx -> num_items = ctx -> unaryExp() -> num_items;
}

void SemanticAnalysis::exitMulExp_mul_unary(CACTParser::MulExp_mul_unaryContext * ctx)
{
    // Check same type
    val_type_t type_1 = (val_type_t)(ctx -> mulExp() -> mul_exp_val_type);
    bool is_array_1   = (bool)(ctx -> mulExp() -> is_array);
    int  num_items_1  = (int)(ctx -> mulExp() -> num_items);
    val_type_t type_2 = (val_type_t)(ctx -> unaryExp() -> unary_exp_val_type);
    bool is_array_2   = (bool)(ctx -> unaryExp() -> is_array);
    int  num_items_2  = (int)(ctx -> unaryExp() -> num_items);
    if(type_1 != type_2){
        std::cout << "Type mismatch: " << type_1 << " and " << type_2 << std::endl;
        exit(COMPILE_ERROR);
    }

    // check array & length/*zty*/
    if(is_array_1 != is_array_2){
        std::cout << "Operation between array and variable." << std::endl;
        exit(COMPILE_ERROR);
    }

    if(is_array_1 && is_array_2 && num_items_1!=num_items_2){
        std::cout << "Operation between arrays with different length." << std::endl;
        exit(COMPILE_ERROR);
    }

    // Type pass
    ctx -> mul_exp_val_type = (int)type_2;
    ctx -> is_const = (ctx -> unaryExp() -> is_const) || (ctx -> mulExp() -> is_const);
    ctx -> is_array = (bool)is_array_2;
    ctx -> is_from_symtab = (ctx -> unaryExp() -> is_from_symtab) || (ctx -> mulExp() -> is_from_symtab);
    ctx -> num_items = (int)num_items_2;

    // Check type for operator
    std::string operand = ctx -> mulOp() -> getText();
    if((operand == "*" || operand == "/") && (type_2 != int_type) && (type_2 != float_type) && (type_2 != double_type)){
        std::cout << "Operator * and / can only be used with int, float or double." << std::endl;
        exit(COMPILE_ERROR);
    }else if((operand == "\%") && (type_2 != int_type)){
        std::cout << "Operator \% can only be used with int." << std::endl;
        exit(COMPILE_ERROR);
    }
}

void SemanticAnalysis::exitAddExp_mul(CACTParser::AddExp_mulContext * ctx)
{
    ctx -> add_exp_val_type = ctx -> mulExp() -> mul_exp_val_type;
    ctx -> is_const = ctx -> mulExp() -> is_const;
    ctx -> is_array = ctx -> mulExp() -> is_array;
    ctx -> is_from_symtab = ctx -> mulExp() -> is_from_symtab;
    ctx -> num_items = ctx -> mulExp() -> num_items;
}

void SemanticAnalysis::exitAddExp_add_mul(CACTParser::AddExp_add_mulContext * ctx)
{
    // Check same type
    val_type_t type_1 = (val_type_t)(ctx -> addExp() -> add_exp_val_type);
    bool is_array_1   = (bool)(ctx -> addExp() -> is_array);
    size_t  num_items_1  = (size_t)(ctx -> addExp() -> num_items);
    val_type_t type_2 = (val_type_t)(ctx -> mulExp() -> mul_exp_val_type);
    bool is_array_2   = (bool)(ctx -> mulExp() -> is_array);
    size_t  num_items_2  = (size_t)(ctx -> mulExp() -> num_items);
    if(type_1 != type_2){
        std::cout << "Type mismatch: " << type_1 << " and " << type_2 << std::endl;
        exit(COMPILE_ERROR);
    }

    if(is_array_1 != is_array_2){
        std::cout << "Operation between array and variable." << std::endl;
        exit(COMPILE_ERROR);
    }

    if(is_array_1 && is_array_2 && num_items_1!=num_items_2){
        std::cout << "Operation between arrays with different length." << std::endl;
        exit(COMPILE_ERROR);
    }

    // bool array in arithmetic operation
    if(type_1 != int_type && type_1 != float_type && type_1 != double_type){
        std::cout << "Arithmetic operation can only be used with int, float and double." << std::endl;
        exit(COMPILE_ERROR);
    }

    ctx -> add_exp_val_type = type_1;
    ctx -> is_const = (ctx -> addExp() -> is_const) || (ctx -> mulExp() -> is_const);
    ctx -> is_array = is_array_1;
    ctx -> is_from_symtab = (ctx -> addExp() -> is_from_symtab) || (ctx -> mulExp() -> is_from_symtab);
    ctx -> num_items = num_items_1;
}

void SemanticAnalysis::exitRelExp_bool(CACTParser::RelExp_boolContext * ctx)
{
    ctx -> rel_exp_val_type = (int)bool_type;
    ctx -> is_array = false;
}

void SemanticAnalysis::exitRelExp_rel_add(CACTParser::RelExp_rel_addContext * ctx)
{
    int type_1 = ctx -> relExp() -> rel_exp_val_type;
    int type_2 = ctx -> addExp() -> add_exp_val_type;
    bool is_array_1 = ctx -> relExp() -> is_array;
    bool is_array_2 = ctx -> addExp() -> is_array;

    // Check for array
    if(is_array_1 == true || is_array_2 == true){
        std::cout << "Type mismatched for array and basic type" << std::endl;
        exit(COMPILE_ERROR);
    }

    // Check for type
    if(type_1 != type_2){
        std::cout << "Type mismatched " << type_1 << " and " << type_2 << std::endl;
        exit(COMPILE_ERROR);
    }

    ctx -> rel_exp_val_type = (int)bool_type;
    ctx -> is_array = false;

    ctx -> is_const = false;
}

void SemanticAnalysis::exitRelExp_add(CACTParser::RelExp_addContext * ctx)
{
    ctx -> rel_exp_val_type = ctx -> addExp() -> add_exp_val_type;
    ctx -> is_array = ctx -> addExp() -> is_array;

    ctx -> is_const = ctx -> addExp() -> is_const;
}

void SemanticAnalysis::exitEqExp(CACTParser::EqExpContext * ctx){
    // Check array
    val_type_t type_2 = (val_type_t)(ctx -> relExp() -> rel_exp_val_type);
    bool is_array_2 = (bool)(ctx -> relExp() -> is_array);
    if(ctx -> eqExp() != nullptr){
        // second branch
        val_type_t type_1 = (val_type_t)(ctx -> eqExp() -> eq_exp_val_type);
        bool is_array_1 = (bool)(ctx -> eqExp() -> is_array);
        if(type_1 != type_2){
            std::cout << "Type mismatch: " << type_1 << " and " << type_2 << std::endl;
            exit(COMPILE_ERROR);
        }
        if(is_array_1 == true || is_array_2 == true){
            std::cout << "logic operation is NOT allowed on an array." << std::endl;
            exit(COMPILE_ERROR);
        }

        // Type pass
        ctx -> eq_exp_val_type = (int)bool_type;
        ctx -> is_array = false;

        ctx -> is_const = false;
    }else{
        // first branch
        ctx -> eq_exp_val_type = (int)type_2;
        ctx -> is_array = (bool)is_array_2;
        ctx -> is_const = ctx -> relExp() -> is_const;
    }
}

void SemanticAnalysis::exitLAndExp(CACTParser::LAndExpContext * ctx){
    // Check array
    val_type_t type_2 = (val_type_t)(ctx -> eqExp() -> eq_exp_val_type);
    bool is_array_2 = (bool)(ctx -> eqExp() -> is_array);
    // Second branch
    if(ctx -> lAndExp() != nullptr){
        val_type_t type_1 = (val_type_t)(ctx -> lAndExp() -> lAnd_exp_val_type);
        bool is_array_1 = (bool)(ctx -> lAndExp() -> is_array);
        if(type_1 != type_2){
            std::cout << "Type mismatch: " << type_1 << " and " << type_2 << std::endl;
            exit(COMPILE_ERROR);
        }
        if(is_array_1 || is_array_2){
            std::cout << "logic operation is NOT allowed on an array." << std::endl;
            exit(COMPILE_ERROR);
        }

        ctx -> lAnd_exp_val_type = (int)bool_type;
        ctx -> is_array = false;

        ctx -> is_const = false;
    }else{
        // Type pass
        ctx -> lAnd_exp_val_type = (int)type_2;
        ctx -> is_array = (bool)is_array_2;
        ctx -> is_const = ctx -> eqExp() -> is_const;
    }
}

void SemanticAnalysis::exitLOrExp(CACTParser::LOrExpContext * ctx){
    // Check array
    val_type_t type_1 = (val_type_t)(ctx -> lAndExp() -> lAnd_exp_val_type);
    bool is_array_1 = (bool)(ctx -> lAndExp() -> is_array);
    // Second branch
    if(ctx -> lOrExp() != nullptr){
        val_type_t type_2 = (val_type_t)(ctx -> lOrExp() -> lOr_exp_val_type);
        bool is_array_2 = (bool)(ctx -> lOrExp() -> is_array);
        if(type_1 != type_2){
            std::cout << "Type mismatch: " << type_1 << " and " << type_2 << std::endl;
            exit(COMPILE_ERROR);
        }
        if(is_array_1 || is_array_2){
            std::cout << "logic operation is NOT allowed on an array." << std::endl;
            exit(COMPILE_ERROR);
        }

        ctx -> lOr_exp_val_type = (int)bool_type;
        ctx -> is_array = false;

        ctx -> is_const = false;
    }else{
        // Type pass
        ctx -> lOr_exp_val_type = (int)type_1;
        ctx -> is_array = (bool)is_array_1;

        ctx -> is_const = ctx -> lAndExp() -> is_const;
    }
}

void SemanticAnalysis::exitConstExp_num(CACTParser::ConstExp_numContext * ctx)
{
    ctx -> const_type = ctx -> number() -> number_type;
    ctx -> is_array = false;
    ctx -> is_const = true;
    ctx -> num_items = 1;
}

void SemanticAnalysis::exitConstExp_bool(CACTParser::ConstExp_boolContext * ctx)
{
    ctx -> const_type = (int)bool_type;
    ctx -> is_array = false;
    ctx -> is_const = true;
    ctx -> num_items = 1;
}

void SemanticAnalysis::exitNumber_int(CACTParser::Number_intContext * ctx)
{
    ctx -> number_type = (int)int_type;
}

void SemanticAnalysis::exitNumber_double(CACTParser::Number_doubleContext * ctx)
{
    ctx -> number_type = (int)double_type;
}

void SemanticAnalysis::exitNumber_float(CACTParser::Number_floatContext * ctx)
{
    ctx -> number_type = (int)float_type;
}


// ----------------------------Error Handling--------------------------
#define ERROR_LEXER 2
#define ERROR_PARSER 3
// Override method generated by ANTLR
void SemanticAnalysis::visitErrorNode(antlr4::tree::ErrorNode * node)
{
    std::cout << "Error encountered." << std::endl;
    exit(COMPILE_ERROR);
}
