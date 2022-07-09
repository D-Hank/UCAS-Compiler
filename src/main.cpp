#include <iostream>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "postGrammarAnalysis.h"
#include "symbolTable.h"
#include "semanticAnalysis.h"
#include "intermediateRepresentation.h"
#include "dataFlowAnalysis.h"
#include "codeGenerate.h"

using namespace antlr4;

SymbolTable symbol_table;
PostGrammarAnalysis post_grammar_stage;
SemanticAnalysis semantic_stage;
IntermediateRepr intermediate_stage;
DataFlow dataflow_stage;
CodeGenerate codegen_stage;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);

    tree::ParseTree *tree = parser.compUnit();

    // Post grammar stage
    // Semantic analysis
    tree::ParseTreeWalker::DEFAULT.walk(&semantic_stage, tree);
    // Intermediate generation
    tree::ParseTreeWalker::DEFAULT.walk(&intermediate_stage, tree);

    // Dataflow analysis
    dataflow_stage.genFlow();

    // Code generation
    codegen_stage.genAsm();
    codegen_stage.outputToFile(argv[1]);


    std::cout << "debug: hello" << std::endl;


    std::cout << "-------------------------Print AST:--------------------------" << std::endl;
    std::cout << tree->toStringTree(&parser) << std::endl;

}
