#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include "BaseObject.hpp"
#include "PrimitiveTypes.hpp"

class ScopeLayer {
public:
  ScopeLayer() = default;
  explicit ScopeLayer(ScopeLayer * parent);
  ~ScopeLayer();

  void add_child_layer();
  ScopeLayer * switch_to_child(const size_t & child_number);
  ScopeLayer * switch_to_parent();

  void declare_variable(const std::string & name, PrimitiveTypes type);
  void init_variable(const std::string & name, std::shared_ptr<BaseObject> object);

  bool is_declared(const std::string & name);
  std::shared_ptr<BaseObject> get_variable(const std::string & name);
  PrimitiveTypes get_variable_type(const std::string & name);
private:
  ScopeLayer * parent_;
  std::vector<ScopeLayer *> children_;

  std::unordered_map<std::string, std::shared_ptr<BaseObject>> values_;
  std::unordered_map<std::string, PrimitiveTypes> types_;

  std::pair<std::unordered_map<std::string, std::shared_ptr<BaseObject>>::iterator, ScopeLayer *> find_(const std::string & name);
};