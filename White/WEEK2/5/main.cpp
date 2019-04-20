#include<iostream>
#include<vector>
#include<string>

void MoveStrings(std::vector<std::string>&source,std::vector<std::string>&destination)
{
    int i{0};
    while(i<source.size())
    {
        destination.push_back(source[i]);
        ++i;
    }
    source.clear();
}

int main()
{
    std::vector<std::string>sourse{"a","b","c"};
    std::vector<std::string>destination{"z","y"};
    MoveStrings(sourse,destination);

    for(auto &s:destination)
        std::cout<<s<<" ";

    return 0;
}
