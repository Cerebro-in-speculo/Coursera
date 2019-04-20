#include <iostream>
#include <vector>

 std::vector<int> Reversed(const std::vector<int> &v)
 {
    auto vCopy=v;
    for(int i=0,k=vCopy.size()-1;i<vCopy.size()/2;++i,--k)
    {
        const int temp=vCopy[i];
        vCopy[i]=vCopy[k];
        vCopy[k]=temp;
    }
    return vCopy;
 }

int main()
{
    std::vector<int>numbers{1,5,8,3,4,9,11};
    std::vector<int>numbersCopy =Reversed(numbers);

    for(auto &v:numbersCopy)
        std::cout<<v<<" ";

    return 0;
}
