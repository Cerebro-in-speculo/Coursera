#include <iostream>
#include<vector>
#include<map>
#include<utility>
#include<sstream>

using namespace std;

template<typename Collection>
string Join(const Collection& c,char d)
{
    stringstream ss;
    bool first=true;
    for(const auto&i:c)
    {
        if(!first)
        {
            ss<<d;
        }
        first=false;
        ss<<i;
    }
    return ss.str();
}


template<typename T>
ostream& operator<<(ostream& stream, const vector<T>&v)
{
    return stream<<'['<<Join(v,',')<<']';
}

template<typename First,typename Second>
ostream& operator<<(ostream& stream, const pair<First,Second>&m)
{
    return  stream<<'('<<m.first<<','<<m.second<<')';
}

template<typename Key,typename Value>
ostream& operator<<(ostream& stream, const map<Key,Value>&m)
{
    return stream<<'{'<<Join(m,',')<<'}';
}

int main()
{
    vector<vector<double>> v{{1.5,3},{2,4.7}};
    cout<<v<<endl;
    map<int,double>m{{1,2.5},{3,4}};
    cout<<m<<endl;

    return 0;
}
