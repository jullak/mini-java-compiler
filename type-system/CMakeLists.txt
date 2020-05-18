target_sources(compiler
        PRIVATE
        ${mini-java-compiler_SOURCE_DIR}/type-system/IntObject.cpp
        ${mini-java-compiler_SOURCE_DIR}/type-system/BoolObject.cpp
        ${mini-java-compiler_SOURCE_DIR}/type-system/IntArrayObject.cpp
        ${mini-java-compiler_SOURCE_DIR}/type-system/BoolArrayObject.cpp)