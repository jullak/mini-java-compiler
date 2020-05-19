#include <stdexcept>

#include "IntObject.hpp"

IntObject::IntObject(const int &val)
  : object_(val)
{}

void IntObject::set_int(const int &val) {
  object_ = val;
}
void IntObject::set_bool(const bool &val) {}

int IntObject::get_int() {
  return object_;
}

bool IntObject::get_bool() {
  throw std::runtime_error("Try to get bool via int");
}

std::vector<int> & IntObject::get_int_array() {
  throw std::runtime_error("Try to get array via int");
}

std::vector<bool> & IntObject::get_bool_array() {
  throw std::runtime_error("Try to get array via int");
}

bool IntObject::is_int() {
  return true;
}

bool IntObject::is_bool() {
  return false;
}

bool IntObject::is_int_array() {
  return false;
}

bool IntObject::is_bool_array() {
  return false;
}