#include <iostream>
#include<string>
#include<set>

void printSet(const std::set<std::string> &s)
{
    for(auto &x:s)
        std::cout<<x<<std::endl;
}

int main()
{
    std::set<std::string>famous_persons;
    famous_persons.insert("Stroustrup");
    famous_persons.insert("Ritci");

    printSet(famous_persons);

    return 0;
}
