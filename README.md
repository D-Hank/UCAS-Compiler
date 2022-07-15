# UCAS-Compiler

## Introduction

Hi. This is a repository for CACT compiler in UCAS. CACT is a subset of C language, with pointers removed and array calculus extension. It is based on the tool ANTLR.

If you find our implementation useful or would like to use our code. Please cite this link.

## Contributors

This work was mostly done by D-Hank (daihankun19@mails.ucas.ac.cn). Also, some tasks were done by Bruce-Sun (sunbin19@mails.ucas.ac.cn) and zty (zhengtianyu@mails.ucas.ac.cn).

## Dependencies

- ANTLR4

- CMake

- G++ -5 (for linking, g++-5 is recommended)

## Principle

Here's the workflow:

```
-------------    -------    -------    ------    ------    -------    -------
|source code| -> | AST | -> | AST | -> | IR | -> | IR | -> | ASM | -> | ASM | -> *.s
-------------    -------    -------    ------    ------    -------    -------
      lexical/syntax  semantic    IR-gen  optimize   ASM-gen   optimize
```

Lexical analysis and syntax parsing are done by ANTLR.

Then we use the AST-visiting interface provided by ANTLR to finish the semantic analysis and generate intermediate code.

We implement part of the backend described in Section 8.5 ~ 8.7 of the Dragon Book.

The compiler can generate RISC-V 64GC assembly instructions for some cases. However, with the lack of manpower, it's not completed yet. We discussed this in detail under the `reports/` folder.

## Running Tips

- Genarate lexer and parser

```shell
cd grammar
antlr4 -Dlanguage=Cpp CACT.g4
```
or use:
```shell
cd grammar
sh code_build.sh
```

- Compile this compiler

```shell
mkdir build
cd build
cmake ..
make
```

- Run demo

```shell
./compiler ../samples/00_main.cact
```

- Run test

```shell
./compiler ../samples/samples_codegen/00_print_int.cact
```

Then `00_print_int.s` will be generated in the same directory.

- Call assembler and linker to generate executable file (if the assembly file is called `test.s`):

```shell
riscv64-unknown-elf-gcc -o test test.s -L./libcact
```

- Run RISCV code on spike emulator:

```shell
spike pk test
```

