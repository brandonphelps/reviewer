

#ifndef TOKEN_ID_H
#define TOKEN_ID_H

#include <string>

namespace TokenId
{
  static const std::string lbrace = "{";
  static const std::string rbrace = "}";
  static const std::string colon  = ":";
  static const std::string comma  = ",";
  static const std::string lbracket = "[";
  static const std::string rbracket = "]";

  static const int string_symbol_id = 0;
  static const int array_symbol_id = 1;
};

#endif
