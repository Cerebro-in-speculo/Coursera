#include <iostream>
#include<vector>
#include<map>

int main()
{
    int q;
    std::cin>>q;

    std::map<std::vector<std::string>,int>buses;

    int busNumber{1};
    int countStop;
    std::string stop;


    while(q>0)
    {
        std::vector<std::string>bus;
        std::cin>>countStop;

        for(int k=0;k<countStop;++k)
        {
            std::cin>>stop;
            bus.push_back(stop);
        }

        if(buses.count(bus)==0)
        {
            ++buses[bus]=busNumber;
            std::cout<<"New bus "<<busNumber<<std::endl;

            ++busNumber;
        }
        else
            std::cout<<"Already exists for "<<buses[bus]<<std::endl;
    --q;
    }
    return 0;
}
