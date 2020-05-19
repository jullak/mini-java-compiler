#include "TemplateVisitor.hpp"

template<typename T>
T TemplateVisitor<T>::accept(ASTElement * element) {
  element->accept(this);
  return tos_value_;
}

template PrimitiveTypes TemplateVisitor<PrimitiveTypes>::accept(ASTElement *element);
template std::shared_ptr<BaseObject> TemplateVisitor<std::shared_ptr<BaseObject>>::accept(ASTElement *element);