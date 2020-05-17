#pragma once

#include "../Elements.hpp"
#include "Visitor.hpp"

template<typename T>
class TemplateVisitor : public Visitor {
public:
  T accept(ASTElement * element);
protected:
  T tos_value_;
};