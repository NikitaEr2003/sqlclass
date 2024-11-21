
#include <iostream>
#include "SqlSelectQueryBuilder.h"
int main()
{
  SqlSelectQueryBuilder query_builder;
  query_builder.AddColumn("name").AddColumn("phone");
  query_builder.AddFrom("students");
  query_builder.AddWhere("id", "42").AddWhere("name", "John");

   std::string answer = query_builder.BuildQuery(); 
   
   std::cout << answer << std::endl;
 
}

