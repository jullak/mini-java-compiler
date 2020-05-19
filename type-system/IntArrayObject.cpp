#include <stdexcept>

#include "IntArrayObject.hpp"

IntArrayObject::IntArrayObject(const int & size) {
  object_.reserve(size);
}

int IntArrayObject::get_int() {
  throw std::runtime_error("Try to get int via int array");
}

bool IntArrayObject::get_bool() {
  throw std::runtime_error("Try to get bool via int array");
}

std::vector<int> & IntArrayObject::get_int_array() {
  return object_;
}

std::vector<bool> & IntArrayObject::get_bool_array() {
  throw std::runtime_error("Try to get bool array via int array");
}

bool IntArrayObject::is_int() {
  return false;
}
bool IntArrayObject::is_bool() {
  return false;
}
bool IntArrayObject::is_int_array() {
  return true;
}
bool IntArrayObject::is_bool_array() {
  return false;
}