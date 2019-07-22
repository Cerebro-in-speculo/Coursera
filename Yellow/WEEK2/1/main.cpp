#include <iostream>
#include<cassert>

using namespace std;

template<typename T>
T Sum(T x,T y){return x+y;}

void TestSum()
{
    assert(Sum(2,3)==5);
    assert(Sum(-2,3)==1);
    assert(Sum(1.2,5.0)==6.2);
    assert(Sum(-2,0)==-2);
    cout<<"TestSum OK"<<endl;
}

int main()
{
    TestSum();
    return 0;
}
