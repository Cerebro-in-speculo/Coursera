#include <iostream>
#include<string>
#include<set>

int main()
{
    int q;
    std::cin>>q;
    std::string s;
    std::set<std::string>firstS;

    while(q>0)
    {
      std::cin>>s;
      firstS.insert(s);
    --q;
    }
    std::cout<<firstS.size()<<std::endl;
    return 0;
}
