#include <iostream>
#include <vector>

 void Reverse(std::vector<int> &v)
 {
    for(int i=0,k=v.size()-1;i<v.size()/2;++i,--k)
    {
        int temp=v[i];
        v[i]=v[k];
        v[k]=temp;
    }
 }

int main()
{
    std::vector<int>numbers{1,5,8,3,4,9,11};
    Reverse(numbers);

    for(auto &v:numbers)
        std::cout<<v<<" ";

    return 0;
}
