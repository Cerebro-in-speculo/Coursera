#include <iostream>
#include<string>

int main()
{
    std::string s{};
    std::cin>>s;

    int k{0};

    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='f')
            ++k;
            if(k==2)
            {
                std::cout<<i<<std::endl;
                break;
            }
    }

    if(k==1)
        std::cout<<-1<<std::endl;
    else if(k==0)
        std::cout<<-2<<std::endl;

    return 0;
}
