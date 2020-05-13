cmake_minimum_required(VERSION 3.0)
project(mini-java-compiler)

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${mini-java-compiler_SOURCE_DIR}/bin)


set (HEADERS Driver.hh parser.hh)

BISON_TARGET(parser-with-ast
        parser.y
        ${mini-java-compiler_SOURCE_DIR}/parser.cpp
        DEFINES_FILE ${mini-java-compiler_SOURCE_DIR}/parser.hh)

FLEX_TARGET(scanner-with-ast
        scanner.l
        ${mini-java-compiler_SOURCE_DIR}/scanner.cpp)

add_executable(compiler
        main.cpp
        Driver.cpp
        Program.cpp
        ${BISON_parser-with-ast_OUTPUTS}
        ${FLEX_scanner-with-ast_OUTPUTS}
        )

target_include_directories(compiler PUBLIC
        ${mini-java-compiler_SOURCE_DIR}/ast
        ${mini-java-compiler_SOURCE_DIR}/ast/statements
        ${mini-java-compiler_SOURCE_DIR}/ast/expressions
        ${mini-java-compiler_SOURCE_DIR}/ast/lvalue
        ${mini-java-compiler_SOURCE_DIR}/ast/types
        ${mini-java-compiler_SOURCE_DIR}/ast/declaration)

add_subdirectory(${mini-java-compiler_SOURCE_DIR}/ast/expressions)
add_subdirectory(${mini-java-compiler_SOURCE_DIR}/ast/statements)
add_subdirectory(${mini-java-compiler_SOURCE_DIR}/ast/lvalue)
add_subdirectory(${mini-java-compiler_SOURCE_DIR}/ast/types)
add_subdirectory(${mini-java-compiler_SOURCE_DIR}/ast/declaration)