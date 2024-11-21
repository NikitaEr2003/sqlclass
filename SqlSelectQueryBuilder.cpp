#include "SqlSelectQueryBuilder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& str) {
  m_colums.push_back(str);
  return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& str) {
  m_table = str;
  return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& str1, const std::string& str2) {
  m_map[str1] = str2;
  return *this;
}

 std::string SqlSelectQueryBuilder::BuildQuery() { 
	std::string result; 

	if (m_colums.empty()) {
          result += "Select";
          result += " *";
    } 
    else {
          result += "Select ";
          int index = 0;
          for (auto& temp : m_colums) {
            
            result += temp;
            index++;
            if (index != m_colums.size()) {
              result += ", ";
            }
            
          }
    }

    result += " FROM ";
    result += m_table;
    result += " WHERE ";
    int index = 1;
    for (auto& [first, second] : m_map) {
      if (m_map.size() == 1) {
       
          result += first + "=" + second; 
          break;
      }
      result += first + "=" + second;
      if (index != m_map.size()) {
        result += " AND ";
      }
     
      index++;

    }

    result += ";";
    
    return result;
}