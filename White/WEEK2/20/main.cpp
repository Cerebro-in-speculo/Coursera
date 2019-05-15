//#include <iostream>
//#include<set>
//include<map>
//#include<string>

std::set<std::string> BuildMapValuesSet(const std::map<int,std::string>&ms)
{
    std::set<std::string> values;
    for(auto &v:ms)
        values.insert(v.second);
    return values;
}

//int main()
//{
//    std::map<int,std::string> mapSet{{1,"add"},{2,"even"},{3,"odd"},{4,"even"},{5,"odd"}};
 //   std::set<std::string>values=BuildMapValuesSet(mapSet);

//    for(auto &v:values)
 //       std::cout<<v<<std::endl;
 //   return 0;
//}
