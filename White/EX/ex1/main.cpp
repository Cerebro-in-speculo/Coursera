#include <iostream>
#include<vector>

int main()
{
    std::vector<std::string>w{"a","b","c"};
    std::vector<std::string>v;

    v=w;
    v[0]="d";

    std::cout<<w[0]<<" "<<w[1]<<std::endl;
    std::cout<<v[0]<<" "<<v[1]<<std::endl;

    return 0;
}
