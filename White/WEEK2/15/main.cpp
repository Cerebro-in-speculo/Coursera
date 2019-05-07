#include <iostream>
#include<string>
#include<vector>
#include<map>

int main()
{
    std::string request;
    std::map<std::string,std::vector<std::string>>route;
    std::string bus;
    int stop_count;
    std::string stop;

    int q{0};
    std::cin>>q;

    while(q>0)
    {
        std::cin>>request;

        if(request=="NEW_BUS")
        {
            std::cin>>bus>>stop_count;

            for(int i=0;i<stop_count;++i)
            {
                std::cin>>stop;
                route[bus].push_back(stop);
            }
        }
        else if(request=="BUSES_FOR_STOP")
        {
            int indStop{0};
            std::cin>>stop;

            for(auto&r:route)
            {
                for(int k=0;k<r.second.size();++k)
                {
                    if(r.second[k]==stop)
                    {
                        std::cout<<r.first<<" ";
                        ++indStop;
                    }
                }
            }
            if(indStop==0)
                std::cout<<"No stop";
            std::cout<<std::endl;
        }

        else if(request=="STOPS_FOR_BUS")
        {
            std::cin>>bus;
            std::vector<std::string>stopBus;

            if(route.count(bus)==0)
                std::cout<<"No bus"<<std::endl;
            else
            {
                stopBus=route[bus];
                for(int k=0;k<stopBus.size();++k)
                {
                    bool indBus=true;
                    std::cout<<"Stop "<<stopBus[k]<<": ";
                    for(auto &r:route)
                    {
                        for(int i=0;i<r.second.size();++i)
                        {
                            if(r.second[i]==stopBus[k]&&r.second!=stopBus)
                            {
                                std::cout<<r.first<<" ";
                                indBus=false;
                            }
                        }
                    }

                    if(indBus)
                        std::cout<<"no interchange";
                    std::cout<<std::endl;
                }
            }
        }
        else if(request=="ALL_BUSES")
        {
            if(route.empty())
                std::cout<<"No buses"<<std::endl;
            else
            {
                for(auto&r:route)
                {
                    std::cout<<"Bus "<<r.first<<": ";
                    for(int k=0;k<r.second.size();++k)
                        std::cout<<r.second[k]<<" ";
                    std::cout<<std::endl;
                }
            }
        }
        --q;
    }

    return 0;
}
