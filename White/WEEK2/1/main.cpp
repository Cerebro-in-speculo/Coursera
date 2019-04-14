#include <iostream>
#include<vector>
#include<string>

int Factorial(int a)
{
    if(a<0)
        return 1;
    else
    {
        int fact{1};
        for(int i=1;i<=a;++i)
            fact*=i;
        return fact;
    }
}

int main()
{
    int a;
    std::cin>>a;

    std::cout<<Factorial(a);

    return 0;
}
