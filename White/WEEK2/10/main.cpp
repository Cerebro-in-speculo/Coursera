#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

int main()
{

    std::vector<int>month{31,28,31,30,31,30,31,31,30,31,30,31};
    int indexMonth{0};

    std::vector<std::vector<std::string>>jobs(31);

    int quit{0};
    std::cin>>quit;
    for(int i=0;i<quit;++i)
    {
        std::string command;
        std::cin>>command;

        if(command=="ADD")
        {
            int day;
            std::string job;
            std::cin>>day>>job;

            jobs[day-1].push_back(job);
        }
        else if(command=="DUMP")
        {
            int day;
            std::cin>>day;
            std::cout<<jobs[day-1].size()<<" ";

            for(auto &j:jobs[day-1])
                std::cout<<j<<" ";
            std::cout<<std::endl;
        }
        else if(command=="NEXT")
        {
            int oldIndex = indexMonth;
            ++indexMonth;

            if(indexMonth==12)
            indexMonth=0;

            if(month[indexMonth]>month[oldIndex])
                jobs.resize(month[indexMonth]);
            else if(month[indexMonth]<month[oldIndex])
            {
                int delta=month[oldIndex]-month[indexMonth];

                for(int i=0;i<delta;++i)
                   jobs[month[indexMonth]-1].insert(end(jobs[month[indexMonth]-1]), begin(jobs[month[oldIndex]-i-1]), end(jobs[month[oldIndex]-i-1]));
                jobs.resize(month[indexMonth]);
            }

        }
    }

    return 0;
}
