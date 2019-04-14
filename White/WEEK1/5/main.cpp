#include <iostream>

int main()
{
    double N,A,B,X,Y;

    do{
     std::cin>>N>>A>>B>>X>>Y;
    }while(A>B);

    if(N<=A)
        std::cout<<N<<std::endl;
    else if (N>A&&N<=B)
        std::cout<<N-(N*X/100.0)<<std::endl;
    else if (N>B)
        std::cout<<N-(N*Y/100.0)<<std::endl;
    return 0;
}
