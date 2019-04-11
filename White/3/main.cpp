#include <iostream>
#include<cmath>

int main()
{
    double A,B,C,D;

    std::cin>>A>>B>>C;

    D=B*B-4*A*C;

    if(D>0&&A!=0)
        std::cout<<(-B+sqrt(D))/(2*A)<<" "<<(-B-sqrt(D))/(2*A)<<std::endl;
    else if(D==0)
        std::cout<<(-B)/(2*A)<<std::endl;
    else if (A==0)
        std::cout<<-C/B<<std::endl;
    else
        std::cout<<std::endl;

    return 0;
}
