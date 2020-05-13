#pragma once

#include <string>

#include "ASTElement.hpp"
#include "Type.hpp"

class Declaration : public ASTElement {
public:
  Declaration(Type * type, const std::string & ident);
  ~Declaration() override;
private:
  Type * type_;
  std::string identifier_;
};