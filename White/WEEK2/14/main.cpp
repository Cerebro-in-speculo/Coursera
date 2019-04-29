#include <iostream>
#include<string>
#include<vector>
#include<map>

int main()
{
    std::string request;
    int index{0};
    std::map<std::string,std::vector<std::vector<std::string>>>route;
    std::string bus;
    int stop_count;
    std::string stop;

    int q{0};
    std::cin>>q;
    std::vector<std::vector<std::string>>stopBus(q);

    while(q>0)
    {
        std::cin>>request;

        if(request=="NEW_BUS")
        {
            std::cin>>bus>>stop_count;

            for(int i=0;i<stop_count;++i)
            {
                std::cin>>stop;
                stopBus[index].push_back(stop);
            }
            route[bus].push_back(stopBus[index]);
            ++index;
        }
        else if(request=="BUSES_FOR_STOP")
        {
            std::cin>>stop;
            for(auto &r:route)
            {
                for(int k=0;k<r.second.size();++k)
                {
                    for(auto &s:r.second[k])
                    {
                        if(stop==s)
                            std::cout<<


                    }

                }
            }
        }
        else if(request=="STOP_FOR_BUS")
        {



        }
        else if(request=="ALL_BUSES")
        {
            if(route.empty())
                std::cout<<"No buses"<<std::endl;
            else
            {
                for(auto &r:route)
                {
                    std::cout<<"Bus "<<r.first<<" ";
                    for(int k=0;k<r.second.size();++k)
                    {
                        for(auto& v:r.second[k])
                            std::cout<<v<<" ";
                    }
                std::cout<<std::endl;
                }
            }
        }
        --q;
    }

    return 0;
}
