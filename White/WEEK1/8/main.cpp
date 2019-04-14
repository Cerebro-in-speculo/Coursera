#include<iostream>

int main()
{
    int a,b;
    std::cin>>a>>b;

    if(a==b)
        std::cout<<a<<std::endl;
    else
    {
        while(a!=0&&b!=0)
        {
            if (a>b)
                a%=b;
            else if (a<b)
                b%=a;
        }
        std::cout<<a+b<<std::endl;
    }
    return 0;
}
