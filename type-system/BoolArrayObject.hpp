#pragma once

#include "BaseObject.hpp"

class BoolArrayObject : public BaseObject {
public:
  explicit BoolArrayObject(const int & size);

  int get_int() override;
  bool get_bool() override;
  std::vector<int> & get_int_array() override;
  std::vector<bool> & get_bool_array() override;
private:
  std::vector<bool> object_;
};