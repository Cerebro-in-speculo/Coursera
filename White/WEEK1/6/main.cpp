#include <iostream>

int main()
{
    int a,b;
    std::cin>>a>>b;

    for(int i=a;i<=b;++i)
    {
        if(i%2==0)
            std::cout<<i<<" ";
    }

    return 0;
}
