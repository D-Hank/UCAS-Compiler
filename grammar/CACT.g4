grammar CACT;

// The language generated
options {
    language = Cpp;
}

@header {
    #include <vector>
    #include <string>
}

/********** Parser **********/
compUnit
    : (decl | funcDef)* EOF
    ;

decl
    : constDecl
    | varDecl
    ;

constDecl
    locals[
        int const_decl_val_type // declared value type
    ]
    : 'const' bType constDef (',' constDef)* ';'
    ;

bType
    locals[
        int btype_val_type
    ]
    : 'int'
    | 'bool'
    | 'float'
    | 'double'
    ;

constDef
    locals[
        std::string id_name,
        int def_val_type,
        bool is_array,
        size_t num_items
    ]
    : Ident ('['IntConst']')?                   #constDef_empty
    | Ident ('['IntConst']')? '=' constInitVal  #constDef_init
    ;

constInitVal
    locals[
        int init_val_type,
        size_t num_items,
        bool is_array,
        std::string value_list
    ]
    : constExp                              #constExp_single
    | '{' (constExp(',' constExp)*)? '}'    #constExp_array
    ;

varDecl
    locals[
        int var_decl_val_type //compare with each variable
    ]
    : bType varDef (',' varDef)* ';'
    ;

varDef
    locals[
        std::string id_name,
        int def_val_type,
        bool is_array,
        size_t num_items
    ]
    : Ident ('['IntConst']')?                   #varDef_empty
    | Ident ('['IntConst']')? '=' constInitVal  #varDef_init
    ;

funcDef
    // Notice: funcType cannot be specified when entering this rule
    : funcHeader block
    ;

funcHeader
    locals[
        std::string *name_to_fill
    ]
    : funcType Ident '(' (funcFParam (','funcFParam)*)? ')'
    ;

funcType
    locals[
        int func_type
    ]
    : 'void'
    | 'int'
    | 'float'
    | 'double'
    | 'bool'
    ;

funcFParam
    locals[
        std::string arg_name,
        int arg_type,
        bool is_array
    ]
    : bType Ident                           #funcFParam_single
    | bType Ident '[' ']'                   #funcFParam_array
    ;

block
    locals[
        bool allow_break = false,       // inherit attribute
        bool allow_continue = false,    // initialization is necessary
        bool allow_return = false,

        bool actual_has_return = false,
        int actual_return_type,

        bool from_func = false,
        std::string *which_func = nullptr,

        int index_in_father,
    ]
    : '{'(blockItem)*'}'
    ;

blockItem
    locals[
        bool allow_break = false,
        bool allow_continue = false,
        bool allow_return = false,

        bool actual_has_return = false,
        int actual_return_type
    ]
    : decl
    | stmt
    ;

stmt
    locals[
        bool allow_break = false,
        bool allow_continue = false,
        bool allow_return = false,

        int stmt_type,          // Seems unnecessary?
        int stmt_val_type,

        bool actual_has_return = false, //synthetic attributes
        int actual_return_type,

        bool else_flag = false,
        std::string while_begin,
        std::string while_end,
        std::string nextlist
    ]
    : lVal '=' exp ';'                                  #stmt_assign
    | (exp)? ';'                                        #stmt_exp
    | block                                             #stmt_block
    | 'if' '('cond')' lab stmt (go lab 'else' stmt)?    #stmt_if
    | 'while' lab '('cond')' lab stmt go                #stmt_while
    | 'break' ';'                                       #stmt_break
    | 'continue' ';'                                    #stmt_continue
    | 'return' (exp)? ';'                               #stmt_return
    ;

lab
    locals[
        std::string use_label,
    ]
    :
    ;

go
    locals[
        std::string goto_label,
    ]
    :
    ;

exp
    locals[
        int exp_val_type,
        bool is_const,
        bool is_array,
        bool is_from_symtab,
        size_t num_items,

        std::string result_name
    ]
    : addExp                                #exp_add
    | BoolConst                             #exp_bool
    ;

cond
    locals[
        std::string truelist,
        std::string falselist,
    ]
    : lOrExp
    ;

lVal
    locals[
        bool is_array,
        bool is_const,
        bool is_from_symtab,
        size_t num_items,
        int lval_type,

        std::string result_name
    ]
    : Ident ('['exp']')?
    ;

primaryExp
    locals[
        int primary_exp_val_type,
        bool is_const,
        bool is_array,
        bool is_from_symtab,
        size_t num_items,

        std::string result_name
    ]
    : '('exp')'                             #primaryExp_exp
    | lVal                                  #primaryExp_lval
    | number                                #primaryExp_num
    ;

//number is at the last of parser

unaryExp
    locals[
        int unary_exp_val_type,
        bool is_const,
        bool is_array,
        bool is_from_symtab,
        size_t num_items,

        std::string result_name
    ]
    : primaryExp                            #unaryExp_primary
    | Ident '('(funcRParams)?')'            #unaryExp_call
    | unaryOp unaryExp                      #unaryExp_uop
    ;

// For 3 - 4: (3) - (4)
// '!' not for array
unaryOp
    : '+' | '-' | '!'
    ;

funcRParams
    : exp (','exp)*
    ;

mulExp
    locals[
        int mul_exp_val_type,
        bool is_const,
        bool is_array,
        bool is_from_symtab,
        size_t num_items,

        std::string result_name
    ]
    : unaryExp                              #mulExp_unary
    | mulExp mulOp unaryExp                 #mulExp_mul_unary
    ;

mulOp
    : '*' | '/' | '%'
    ;

addExp
    locals[
        int add_exp_val_type,
        bool is_const,
        bool is_array,
        bool is_from_symtab,
        size_t num_items,

        std::string result_name
    ]
    : mulExp                                #addExp_mul
    | addExp addOp mulExp                   #addExp_add_mul
    ;

addOp
    : '+' | '-'
    ;

relExp
    locals[
        int rel_exp_val_type,
        bool is_array,
        bool is_const,
        
        std::string truelist,
        std::string falselist,
        std::string result_name
    ]
    : addExp                                #relExp_add
    | relExp relOp addExp                   #relExp_rel_add
    | BoolConst                             #relExp_bool
    ;

relOp
    : '<' | '>' | '<=' | '>='
    ;

eqExp
    locals[
        int eq_exp_val_type,
        bool is_array,
        bool is_const,
        
        std::string truelist,
        std::string falselist,
        std::string result_name
    ]
    : relExp
    | eqExp eqOp relExp
    ;

eqOp
    : '==' | '!='
    ;

lAndExp
    locals[
        int lAnd_exp_val_type,
        bool is_array,
        bool is_const,

        std::string truelist,
        std::string falselist,
        std::string result_name
    ]
    : eqExp 
    | lAndExp lab '&&' eqExp
    ;

lOrExp
    locals[
        int lOr_exp_val_type,
        bool is_array,
        bool is_const,

        std::string truelist,
        std::string falselist,
        std::string result_name
    ]
    : lAndExp
    | lOrExp lab '||' lAndExp
    ;

constExp
    locals[
        int const_type,
        bool is_const,        
        bool is_array,
        size_t num_items,

        std::string const_value
    ]
    : number                                #constExp_num
    | BoolConst                             #constExp_bool
    ;

number
    locals[
        int number_type,
        std::string number_value
    ]
    : IntConst                              #number_int
    | DoubleConst                           #number_double
    | FloatConst                            #number_float
    ;

/********** Lexer **********/
BoolConst : 'true' | 'false';

Ident
    : IdentNondigit [a-zA-Z_0-9]*
    ;

fragment
IdentNondigit
    : [a-zA-Z_]
    ;

fragment
Digit
    : [0-9]
    ;

IntConst
    : DecimalConst 
    | OctalConst
    | HexadecimalConst
    ;

fragment
DecimalConst
    : '0'
    | NonzeroDigit Digit*
    ;

fragment
OctalConst
    : '0' OctalDigit+
    ;

fragment
HexadecimalConst
    : HexadecimalPrefix HexadecimalDigit+
    ;

fragment
NonzeroDigit
    : [1-9]
    ;

fragment
OctalDigit
    : [0-7]
    ;

fragment
HexadecimalPrefix
    : '0x'
    | '0X'
    ;

fragment
HexadecimalDigit
    : [0-9a-fA-F]
    ;

FloatConst
    : DoubleConst FloatSuffix
    ;

fragment
FloatSuffix
    : 'F' | 'f'
    ;

DoubleConst
    : DecimalFraction Exponent?
    | Digit+ Exponent
    ;

fragment
DecimalFraction
    : Digit+ '.' Digit+
    | '.' Digit+
    | Digit+ '.'
    ;

fragment
Exponent
    : ExponentPrefix Sign? Digit+
    ;

fragment
ExponentPrefix
    : 'E' | 'e'
    ;

fragment
Sign
    : '+' | '-'
    ;

NewLine
    : ('\r' '\n'? | '\n') 
      -> skip
    ;

WhiteSpace
    : [ \t]+
      -> skip
    ;

BlockComment
    : '/*' .*? '*/'
      -> skip
    ;

LineComment
    : '//' ~[\r\n]*
      -> skip
    ;
