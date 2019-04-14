#include <iostream>
#include<string>

bool IsPalindrom(std::string s)
{
    for(int i=0,k=s.size()-1;i<s.size();++i,--k)
    {
        if(s[i]!=s[k])
            return false;
    }
    return true;
}

int main()
{
    std::string s;
    std::cin>>s;

    std::cout<<IsPalindrom(s);


    return 0;
}
