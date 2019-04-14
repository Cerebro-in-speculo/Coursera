#include <iostream>

int main()
{
    int A,B;
    std::cin>>A>>B;

    if(B!=0)
        std::cout<<A/B<<std::endl;
    else
        std::cout<<"Impossible"<<std::endl;

    return 0;
}
