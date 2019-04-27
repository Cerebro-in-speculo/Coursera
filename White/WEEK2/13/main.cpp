#include <iostream>
#include<map>
#include<string>

int main()
{
    std::string request;
    std::string country;
    std::string capital;

    int q;
    std::cin>>q;

    std::map<std::string,std::string>directory;


    while(q>0)
    {
        std::cin>>request;

        if(request=="CHANGE_CAPITAL")
        {
            std::cin>>country>>capital;

            if(directory.count(country)==0)
            {
                directory[country]=capital;
                std::cout<<"Introduce new country "<<country<<" with capital "<<capital<<std::endl;
            }
            else
            {
                for(auto &c:directory)
                {
                    if(c.first==country&&c.second==capital)
                        std::cout<<"Country "<<country<<" hasn't changed its capital"<<std::endl;
                    else if(c.first==country&&c.second!=capital)
                    {
                        std::cout<<"Country "<<country<<" has changed its capital from "<<directory[country]<<" to "<<capital<<std::endl;
                        directory[country]=capital;
                    }
                }
            }
        }

        if (request=="RENAME")
        {
            std::string country_old;
            std::cin>>country_old>>country;

            if(directory.count(country_old)==0||country_old==country||directory.count(country)==1)
                std::cout<<"Incorrect rename, skip"<<std::endl;
            else
            {
                for(auto &c:directory)
                {
                    if(c.first==country_old)
                    {
                        std::cout<<"Country "<<c.first<<" with capital "<<c.second<<" has been renamed to "<<country<<std::endl;
                        directory[country]=c.second;
                        directory.erase(country_old);
                    }
                }
            }
        }

        if(request=="DUMP")
        {
            int score{0};

            for(auto &c:directory)
                ++score;

            if(score)
            {
                for(auto &c:directory)
                    std::cout<<c.first<<"/"<<c.second<<" ";
                std::cout<<std::endl;
            }
            else
                std::cout<<"There are no countries in the world"<<std::endl;
        }

        if(request=="ABOUT")
        {
            std::cin>>country;

                if(directory.count(country)==0)
                    std::cout<<"Country "<<country<<" doesn't exist."<<std::endl;
                else
                    std::cout<<"Country "<<country<<" has capital "<<directory[country]<<std::endl;
        }
        --q;
    }
    return 0;
}
