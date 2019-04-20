#include <iostream>
#include <vector>
#include<string>

void temperSA(const std::vector<int>&v,int total)
{
    int k=0;
    for(auto &s:v)
    {
        if(s>total)
        ++k;
    }
    std::cout<<k<<std::endl;

    for(int i=0;i<v.size();++i)
    {
        if(v[i]>total)
            std::cout<<i<<" ";
    }
}

int main()
{
    int d,total{0};

    std::cin>>d;

    std::vector<int>v(d);
    for(auto&s:v)
    {
        std::cin>>s;
        total+=s;
    }

    temperSA(v,total/=d);

    return 0;
}
