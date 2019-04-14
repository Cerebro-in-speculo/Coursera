#include <iostream>
#include<cmath>

int main()
{
    double A,B,C,D;

    std::cin>>A>>B>>C;

    //Ax² + Bx + C = 0
    D=B*B-4*A*C;

    if((B==0&&C==0)||A==0&&C==0)
        std::cout<<0<<std::endl;
    else if(B!=0&&C==0&&A!=0)
        std::cout<<0<<" "<<(-B)/A<<std::endl;
    else if(B==0&&C!=0&&A!=0)
         std::cout<<std::endl;
    else if(D>0&&A!=0)
        std::cout<<(-B+sqrt(D))/(2*A)<<" "<<(-B-sqrt(D))/(2*A)<<std::endl;
    else if(D==0&&A!=0)
        std::cout<<(-B)/(2*A)<<std::endl;
    else if(A==0&&B!=0&&C!=0)
        std::cout<<-C/B<<std::endl;
    else if(D<0||(A==0&&B==0))
        std::cout<<std::endl;
    return 0;
}
