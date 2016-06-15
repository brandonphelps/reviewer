

#include "json_dict.h"


JsonDict::JsonDict()
{
  
}

JsonDict::JsonDict(const JsonDict& map)
{
  
}

void JsonDict::setString(const std::string& key, const std::string& value)
{
  m_string_map[key] = value;
}

std::string JsonDict::getString(const std::string& key)
{
  return m_string_map[key];
}

void JsonDict::setArray(const std::string& key, const std::vector<std::string>& value)
{
  m_string_vector_map[key] = value;
}

std::vector<std::string> JsonDict::getArray(const std::string& key)
{
  return m_string_vector_map[key];
}
