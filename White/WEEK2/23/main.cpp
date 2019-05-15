#include <iostream>
#include<set>
#include<map>
#include<string>

int main()
{
    int stopCount;
    int number{0};
    std::string stop;
    std::map<std::set<std::string>,int>stopBus;

    int q;
    std::cin>>q;

    while(q>0)
    {
        std::set<std::string>numberBus;
        std::cin>>stopCount;

        for(int k=0;k<stopCount;++k)
        {
            std::cin>>stop;
            numberBus.insert(stop);
        }

        if(stopBus[numberBus]==0)
        {
            std::cout<<"New bus "<<++number<<std::endl;
            stopBus[numberBus]=number;
        }
        else
            std::cout<<"Already exists for "<<stopBus[numberBus]<<std::endl;
    --q;
    }
    return 0;
}
