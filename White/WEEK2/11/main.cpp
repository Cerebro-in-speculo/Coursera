#include <iostream>
#include<map>
#include<vector>

void printMap(const std::map<std::string,int>&m)
{
    std::cout<<m.size()<<std::endl;
    for(const auto &item:m)
        std::cout<<item.first<<" : "<<item.second<<std::endl;
}


int main()
{
    std::vector<std::string>words{"one","two","one"};

    std::map<std::string,int>counters;


    return 0;
}
