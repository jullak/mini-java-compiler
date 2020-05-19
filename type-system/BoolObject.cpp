#include <stdexcept>

#include "BoolObject.hpp"

BoolObject::BoolObject(const bool &val)
  : object_(val)
{}

void BoolObject::set_bool(const bool &val) {
  object_ = val;
}
void BoolObject::set_int(const int &val) {}

int BoolObject::get_int() {
  throw std::runtime_error("Try to get int via bool");
}

bool BoolObject::get_bool() {
  return object_;
}

std::vector<int> & BoolObject::get_int_array() {
  throw std::runtime_error("Try to get array via int");
}

std::vector<bool> & BoolObject::get_bool_array() {
  throw std::runtime_error("Try to get array via int");
}

bool BoolObject::is_bool() {
  return true;
}
bool BoolObject::is_int() {
  return false;
}
bool BoolObject::is_int_array() {
  return false;
}
bool BoolObject::is_bool_array() {
  return false;
}