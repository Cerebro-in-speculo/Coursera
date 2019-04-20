#include <iostream>
#include<algorithm>
#include<vector>
#include<chrono>

void UpdateIfGreater(const int &first,int &second)
{
    if (first>second)
        second=first;
}

int main()
{
    int a=4;
    int b=2;
    std::cout<<a<<" "<<b<<'\n';
    UpdateIfGreater(a,b);
    std::cout<<a<<" "<<b;
    return 0;
}
