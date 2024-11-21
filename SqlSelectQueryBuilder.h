#pragma once
#include <string>
#include <vector>
#include <map>
class SqlSelectQueryBuilder 
{
  std::map<std::string, std::string> m_map;
  std::vector<std::string> m_colums;
  std::string m_table;

 public:
  SqlSelectQueryBuilder& AddColumn(const std::string& str);
  SqlSelectQueryBuilder& AddFrom(const std::string& str);
  SqlSelectQueryBuilder& AddWhere(const std::string& str1, const std::string& str2);
  std::string BuildQuery(); 


};
