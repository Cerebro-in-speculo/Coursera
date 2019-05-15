#include <iostream>
#include<string>
#include<map>
#include<vector>
#include<set>

int main()
{
    int number{0};
    std::string option;
    std::string world1,world2,world;
    std::map<int,std::vector<std::string>>dictionary;


    int q;
    std::cin>>q;

    while(q>0)
    {
        std::cin>>option;
        if(option=="ADD")
        {
            std::cin>>world1>>world2;
            dictionary[++number]={world1,world2};
        }
        else if(option=="COUNT")
        {
            int countIndex{0};
            std::vector<std::string>v;
            std::cin>>world;
            for(auto &d:dictionary)
            {
                v=d.second;
                for(int k=0;k<v.size();++k)
                {
                    if(v[k]==world)
                    ++countIndex;
                }
            }
            std::cout<<countIndex<<std::endl;
        }
        else if(option=="CHECK")
        {
            std::cin>>world1>>world2;
            bool flag=false;
            for(auto &d:dictionary)
            {
                std::set<std::string>s(begin(d.second),end(d.second));
                s.insert(world1);s.insert(world2);
                if(s.size()==2)
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
