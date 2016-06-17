
#ifndef JSON_DICT_H
#define JSON_DICT_H


#include <string>
#include <map>
#include <vector>

class JsonDict
{
public:
  JsonDict();
  JsonDict(const JsonDict& map);

  void setString(const std::string& key, const std::string& value);
  std::string getString(const std::string& key);

  void setArray(const std::string& key, const std::vector<std::string>& value);

  std::vector<std::string> getArray(const std::string& key);

  void clear();

private:
  std::map<std::string, std::string> m_string_map;
  std::map<std::string, std::vector<std::string> > m_string_vector_map;
  std::map<std::string, JsonDict> m_dict_map;
};

#endif
