#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Type.hpp"

class Declaration : public virtual ASTElement {
public:
  Declaration(Type * type, const std::string & ident);
  ~Declaration() override;

  void accept(Visitor * visitor) override ;

  Type * type_;
  std::string identifier_;
};