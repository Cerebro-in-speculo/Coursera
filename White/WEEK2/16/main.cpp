#include <iostream>
#include<string>
#include<vector>
#include<map>

int main()
{
    std::string request;
    std::map<std::string,std::vector<std::string>>busStop;
    std::map<std::string,std::vector<std::string>>stopBus;
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
            for(int k=0;k<stop_count;++k)
            {
                std::cin>>stop;
                busStop[bus].push_back(stop);
                stopBus[stop].push_back(bus);
            }
        }
        else if(request=="BUSES_FOR_STOP")
        {
            std::vector<std::string>vStopBus;
            std::cin>>stop;
            if(stopBus.count(stop)==0)
                std::cout<<"No stop";
            else
            {
                vStopBus=stopBus[stop];
                    for(int k=0;k<vStopBus.size();++k)
                        std::cout<<vStopBus[k]<<" ";
            }
            std::cout<<std::endl;
        }

        else if(request=="STOPS_FOR_BUS")
        {
            std::cin>>bus;
            std::vector<std::string>vBusStop;
            std::vector<std::string>vStopBus;


            if(busStop.count(bus)==0)
                std::cout<<"No bus"<<std::endl;
            else
            {
                vBusStop=busStop[bus];
                for(int k=0;k<vBusStop.size();++k)
                {
                    std::cout<<"Stop "<<vBusStop[k]<<": ";
                    if(stopBus[vBusStop[k]].size()==1)
                        std::cout<<"no interchange";
                    else
                    {
                        vStopBus=stopBus[vBusStop[k]];
                        for(int k=0;k<vStopBus.size();++k)
                        {
                            if(vStopBus[k]!=bus)
                            std::cout<<vStopBus[k]<<" ";
                        }
                    }
                    std::cout<<std::endl;
                }
            }
        }
        else if(request=="ALL_BUSES")
        {
            if(busStop.empty())
                std::cout<<"No buses"<<std::endl;
            else
            {
                for(auto &bs:busStop)
                {
                    std::cout<<"Bus ";
                    std::cout<<bs.first<<": ";
                    for(int k=0;k<bs.second.size();++k)
                        std::cout<<bs.second[k]<<" ";
                    std::cout<<std::endl;
                }
            }
        }
        --q;
    }

    return 0;
}

