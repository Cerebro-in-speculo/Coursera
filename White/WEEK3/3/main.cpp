#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<ctype.h>

int main()
{
    int n;
    std::cin>>n;

    std::vector<std::string>v(n);
    for(std::string &i:v)
        std::cin>>i;

    std::sort(begin(v),end(v),[v](std::string s1,std::string s2){
        for(int k=0;k<s1.size();++k)
            s1[k]=tolower(s1[k]);
        for(int k=0;k<s2.size();++k)
            s2[k]=tolower(s2[k]);
        return s1<s2;
    });

    for(std::string &i:v)
        std::cout<<i<<' ';

    return 0;
}
