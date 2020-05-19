#include <stdexcept>

#include "ScopeLayer.hpp"

ScopeLayer::ScopeLayer(ScopeLayer *parent)
  : parent_(parent)
{}

ScopeLayer::~ScopeLayer() {
  for (auto layer : children_) {
    delete layer;
  }
}

void ScopeLayer::add_child_layer() {
  children_.push_back(new ScopeLayer(this));
}

ScopeLayer * ScopeLayer::switch_to_child(const size_t &child_number) {
  return children_[child_number];
}

ScopeLayer * ScopeLayer::switch_to_parent() {
  return parent_;
}

void ScopeLayer::declare_variable(const std::string & name, PrimitiveTypes type) {
  if (values_.find(name) != values_.end()) {
    throw std::runtime_error("Double var declaration!");
  }

  values_.insert(std::make_pair(name, nullptr));
  types_.insert(std::make_pair(name, type));
}

void ScopeLayer::init_variable(const std::string &name, std::shared_ptr<BaseObject> object) {
  if (!is_declared(name)) {
    throw std::runtime_error("Initialize var before declare!");
  }

  values_[name] = std::move(object);
}

bool ScopeLayer::is_declared(const std::string &name) {
  auto it_and_layer = find_(name);
  return !(it_and_layer.second == nullptr
           || (it_and_layer.second != nullptr && it_and_layer.first == it_and_layer.second->values_.end()));
}

std::shared_ptr<BaseObject> ScopeLayer::get_variable(const std::string &name) {
  auto it_and_layer = find_(name);
  if (it_and_layer.second == nullptr
      || (it_and_layer.second != nullptr && it_and_layer.first == it_and_layer.second->values_.end())) {
    throw std::runtime_error("Use var before declare!");
  } else if (it_and_layer.first->second == nullptr) {
    throw std::runtime_error("Use var before init!");
  }

  return it_and_layer.first->second;
}

PrimitiveTypes ScopeLayer::get_variable_type(const std::string &name) {
  ScopeLayer * current_layer = this;

  while (current_layer->types_.find(name) == current_layer->types_.end() && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }

  if (current_layer->types_.find(name) == current_layer->types_.end()) {
    throw std::runtime_error("Use var before declare!");
  }

  return current_layer->types_.find(name)->second;
}

std::pair<std::unordered_map<std::string, std::shared_ptr<BaseObject>>::iterator, ScopeLayer *>
ScopeLayer::find_(const std::string &name) {
  ScopeLayer * current_layer = this;

  while (current_layer->values_.find(name) == current_layer->values_.end() && current_layer->parent_ != nullptr) {
    current_layer = current_layer->parent_;
  }

  return std::make_pair(current_layer->values_.find(name), current_layer);
}