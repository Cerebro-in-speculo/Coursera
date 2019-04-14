#include <iostream>
#include<vector>

int main()
{
    int a;
    std::cin>>a;

    std::vector<int>v;

    while(a>0)
    {
        if(a%2>0)
            v.push_back(1);
        else
            v.push_back(0);
        a/=2;
    }

    for(int i=v.size()-1;i>=0;--i)
    std::cout<<v[i];

    return 0;
}
