#include "TemplateVisitor.hpp"

template<typename T>
T TemplateVisitor<T>::accept(ASTElement * element) {
  element->accept(this);
  return tos_value_;
}