#pragma once

#include <vector>

#include "postGrammarAnalysis.h"
#include "intermediateRepresentation.h"
#include "symbolTable.h"

// ---------------------------------NOTICE-----------------------------------

extern SymbolTable symbol_table;
extern PostGrammarAnalysis post_grammar_stage;
extern IntermediateRepr intermediate_stage;


/**
 * Definition of class BasicBlock
 */
class BasicBlock {
private:
    size_t start_inst;  // [start, end)
    size_t end_inst;

    std::vector < size_t > inst_array;  // Includes which instructions

    std::vector < BasicBlock * > pre;
    std::vector < BasicBlock * > next;

public:
    /**
     * Constructor
     */
    BasicBlock(size_t start_inst, size_t end_inst = 0) {
        this -> start_inst = start_inst;
        this -> end_inst = end_inst;
    }
    /**
     * Destructor
     */
    ~BasicBlock() {
        for (size_t i = 0; i < pre.size(); i ++) {
            delete pre[i];
        }
        for (size_t i = 0; i < next.size(); i ++) {
            delete next[i];
        }
    }
    /**
     * Append an inst
     */
    void appendInst(size_t id) {
        inst_array.push_back(id);
    }
    /**
     * Get start inst
     */
    size_t getStart() {
        return start_inst;
    }
    /**
     * Get end inst
     */
    size_t getEnd() {
        return end_inst;
    }
    /**
     * Set end inst
     */
    void setEnd(size_t end) {
        this -> end_inst = end;
    }
};

class DataFlow {
private:
    std::vector < BasicBlock * > block_array;
    std::vector < size_t > leader;

public:
    /**
     * Constructor
     */
    DataFlow() {};
    /**
     * Destructor
     */
    ~DataFlow() {};
    /**
     * Generate data flow
     */
    void genFlow() {
        genFlowGraph();
        macIndependOpt();
    }
    /**
     * Generate flow graph
     * Now we only gen basic blocks
     */
    void genFlowGraph() {
        genBasicBlock();
    }
    /**
     * Generate basic blocks
     */
    void genBasicBlock();
    /**
     * Generate leaders
     */
    void genLeader();
    /**
     * Machine-independent optimization
     * Now we just leave it empty
     */
    void macIndependOpt() {
        ;
    };
};
