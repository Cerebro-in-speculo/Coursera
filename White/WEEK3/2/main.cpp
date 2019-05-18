#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>

int main()
{
    int n,a;
    std::cin>>n;

    int date[n];
    for(int i=0;i<n;++i)
    {
        std::cin>>a;
        date[i]=a;
    }
    std::vector<int>v(date,date+n);
    std::sort(begin(v),end(v),[](int x,int y){
        return (abs(x)<abs(y));
    });

    for(auto &i:v)
        std::cout<<i<<" ";
    std::cout<<std::endl;

    return 0;
}
