#include <iostream>
#include<algorithm>
#include<string>
#include<vector>

void printV(const std::vector<int>&v)
{
    for(auto &vs:v)
        std::cout<<vs<<" ";
}

int main()
{
    std::vector<int>v{1,3,2,5,4,2};
    for(int k=0;k<v.size();++k)
        ++v[k];
    printV(v);

    std::cout<<std::endl;
    for(auto &i:v)
        ++i;
    printV(v);

    return 0;
}
