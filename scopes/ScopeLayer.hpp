#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "BaseObject.hpp"
#include "PrimitiveTypes.hpp"

class ScopeLayer {
public:
  explicit ScopeLayer(ScopeLayer * parent);
  ~ScopeLayer();

  void add_child_layer();
  ScopeLayer * switch_to_child(const size_t & child_number);
  ScopeLayer * switch_to_parent();

  void declare_variable(const std::string & name, PrimitiveTypes type);
  void init_variable(const std::string & name, BaseObject * object);

  bool is_declared(const std::string & name);
  BaseObject * get_variable(const std::string & name);
private:
  ScopeLayer * parent_;
  std::vector<ScopeLayer *> children_;

  std::unordered_map<std::string, BaseObject * > values_;
  std::unordered_map<std::string, PrimitiveTypes> types_;

  std::pair<std::unordered_map<std::string, BaseObject *>::iterator, ScopeLayer *> find_(const std::string & name);
};