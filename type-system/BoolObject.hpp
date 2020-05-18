#pragma once

#include "BaseObject.hpp"

class BoolObject : public BaseObject {
public:
  explicit BoolObject(const bool & val);

  int get_int() override;
  bool get_bool() override;
  std::vector<int> & get_int_array() override;
  std::vector<bool> & get_bool_array() override;
private:
  bool object_;
};
