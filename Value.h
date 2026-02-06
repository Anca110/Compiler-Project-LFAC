#pragma once
#include <string>
#include <iostream>

struct Value
{
  enum Type
  {
    INT,
    FLOAT,
    BOOL,
    STRING,
    UNDEF
  };

  Type type;

  int i;
  float f;
  bool b;
  std::string s;

  Value()
  {
    type = UNDEF;
    i = 0;
    f = 0.0f;
    b = false;
    s = "";
  }

  Value(int v)
  {
    type = INT;
    i = v;
  }

  Value(float v)
  {
    type = FLOAT;
    f = v;
  }

  Value(bool v)
  {
    type = BOOL;
    b = v;
  }

  Value(std::string v)
  {
    type = STRING;
    s = v;
  }

  static Value defaultFor(Type t)
  {
    if (t == INT)
      return Value(0);

    if (t == FLOAT)
      return Value(0.0f);

    if (t == BOOL)
      return Value(false);

    if (t == STRING)
      return Value("");

    return Value();
  }


  std::string toString()
  {
    if (type == INT)
      return std::to_string(i);

    if (type == FLOAT)
      return std::to_string(f);

    if (type == BOOL)
    {
      if (b == true)
        return "true";
      else
        return "false";
    }

    if (type == STRING)
      return s;

    return "undef";
  }
};

