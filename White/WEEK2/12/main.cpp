#include <iostream>
#include<map>
#include<string>

bool BuildCharCounters(std::string s1,std::string s2)
{
    std::map<char,int>m1;
    std::map<char,int>m2;

    for(char &s:s1)
        ++m1[s];

    for(char &s:s2)
        ++m2[s];

    return m1==m2;
}

int main()
{
    std::string s1,s2;

    int q;
    std::cin>>q;

    while(q>0)
    {
        std::cin>>s1>>s2;

        if(BuildCharCounters(s1,s2))
            std::cout<<"YES"<<std::endl;
        else
            std::cout<<"NO"<<std::endl;
    --q;
    }
    return 0;
}
