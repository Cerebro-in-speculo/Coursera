#include <iostream>
#include<string>
#include<map>
#include<set>
#include<vector>

int main()
{
    std::string option;
    std::string world1,world2,world;

    std::map<std::string,std::set<std::string>>dictionary;

    int q;
    std::cin>>q;


    while(q>0)
    {
        std::cin>>option;
        if(option=="ADD")
        {
            std::cin>>world1>>world2;
            dictionary[world1].insert(world2);
            dictionary[world2].insert(world1);
        }
        else if(option=="COUNT")
        {
            std::cin>>world;
            std::cout<<dictionary[world].size()<<std::endl;
        }
        else if(option=="CHECK")
        {
            bool flag=false;
            std::cin>>world1>>world2;
            for(auto &d:dictionary[world1])
            {
                if(d==world2)
                    flag=true;
            }

            if(flag)
                std::cout<<"YES"<<std::endl;
            else
                std::cout<<"NO"<<std::endl;
        }
    --q;
    }
    return 0;
}
