#include <iostream>
#include<string>
#include<vector>


bool IsPalindrom(std::string s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words,int minLength)
{
    std::vector<std::string>returnPalindrom;

    for(auto &s:words)
    {
        if(IsPalindrom(s)&&s.size()>=minLength)
            returnPalindrom.push_back(s);
    }
    return returnPalindrom;
}

int main()
{
    int minLength;
    std::cin>>minLength;

    std::vector<std::string> v{"abacaba","aba"};

    for(auto &s:PalindromFilter(v,minLength))
        std::cout<<s<<" ";

    return 0;
}
