

#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "json_dict.h"

class JsonParser
{
public:
  JsonParser();

  JsonDict parse(const std::string& filename);

private:
  int get_char();

  bool is_symbol(const std::string& symbol);

  void get_next_symbol();

  bool is_string(const std::string& symbol);

  bool accept(const std::string& symbol);
  bool accept(int symbol_id);

  bool lbrace_symbol();
  bool rbrace_symbol();
  bool string_symbol();
  // recursive list of string, string
  bool string_list_symbol();
  // calls the above and includes the [ and ]
  bool string_vector_symbol();
  bool key_symbol();
  bool colon_symbol();
  bool value_symbol();

  bool dict_entry_symbol();
  bool dict_entry_list_symbol();
  bool dictionary_symbol();

  bool start_symbol();

private:

  std::string m_current_symbol;
  std::string m_prev_symbol;

  std::vector<std::string> m_string_vector;

  char m_current_char;

  std::vector<std::string> m_symbol_vector;

  std::string m_current_key;
  std::string m_current_value;

  JsonDict m_data;

private:
  std::ifstream m_instream;
};

#endif
