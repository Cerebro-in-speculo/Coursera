#include <iostream>
#include<vector>
#include<string>

void worryPeople(std::vector<int>&v,std::string command,int valuePeople)
{
    if(command=="COME"&&valuePeople>0)
    {
        int i=0;
        while(i<valuePeople)
        {
            v.push_back(0);
            ++i;
        }
    }
    else if(command=="COME"&&valuePeople<0)
    {
        int i=0;
        while(i>valuePeople)
        {
            v.pop_back();
            --i;
        }
    }
    if(command=="WORRY")
        v[valuePeople]=1;
    if(command=="QUIET")
        v[valuePeople]=0;
}

int worryPeople(std::vector<int>&v)
{
        int i=0;
        for(auto &w:v)
        {
            if(w==1)
                ++i;
        }
        return i;
}

int main()
{
    int count_p,i=0;
    std::cin>>count_p;
    int valuePeople;
    std::string command;

    std::vector<int>v;
    std::vector<int>rezult;

    while(i<count_p)
    {
        std::cin>>command;
        if(command=="WORRY_COUNT")
            rezult.push_back(worryPeople(v));
        else
        {
            std::cin>>valuePeople;
            worryPeople(v,command,valuePeople);
        }
        ++i;
    }

    for(auto &k:rezult)
        std::cout<<k<<'\n';

    return 0;
}
