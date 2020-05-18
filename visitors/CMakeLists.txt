target_sources(compiler
        PRIVATE
        ${mini-java-compiler_SOURCE_DIR}/visitors/TemplateVisitor.cpp
        ${mini-java-compiler_SOURCE_DIR}/visitors/PrintVisitor.cpp
        ${mini-java-compiler_SOURCE_DIR}/visitors/ScopeBuilderVisitor.cpp
        ${mini-java-compiler_SOURCE_DIR}/visitors/TypeValidatorVisitor.cpp)