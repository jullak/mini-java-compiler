#pragma once

#include <vector>

class BaseObject {
public:
  virtual ~BaseObject() {}

  virtual int get_int() = 0;
  virtual bool get_bool() = 0;
  virtual std::vector<int> & get_int_array() = 0;
  virtual std::vector<bool> & get_bool_array() = 0;

  virtual bool is_int() = 0;
  virtual bool is_bool() = 0;
  virtual bool is_int_array() = 0;
  virtual bool is_bool_array() = 0;

  virtual void set_int(const int & val) = 0;
  virtual void set_bool(const bool & val) = 0;
};