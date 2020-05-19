#include "stdexcept"

#include "BoolArrayObject.hpp"

BoolArrayObject::BoolArrayObject(const int & size) {
  object_.reserve(size);
}

int BoolArrayObject::get_int() {
  throw std::runtime_error("Try to get int via bool array");
}

bool BoolArrayObject::get_bool() {
  throw std::runtime_error("Try to get bool via bool array");
}

std::vector<int> & BoolArrayObject::get_int_array() {
  throw std::runtime_error("Try to get int array via bool array");
}

std::vector<bool> & BoolArrayObject::get_bool_array() {
  return object_;
}

bool BoolArrayObject::is_int() {
  return false;
}
bool BoolArrayObject::is_bool() {
  return false;
}
bool BoolArrayObject::is_int_array() {
  return false;
}
bool BoolArrayObject::is_bool_array() {
  return true;
}