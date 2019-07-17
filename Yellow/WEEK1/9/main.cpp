#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <sstream>
using namespace std;

template<typename Collection>Collection Sqr(Collection x);
template<typename T> vector<T> operator*(vector<T> p1,vector<T> p2);
template<typename First,typename Second> pair<First,Second>operator*(const pair<First,Second>&p1,const pair<First,Second>&p2);
template<typename Key,typename Value> map<Key,Value>operator*(const map<Key,Value>&m1,const map<Key,Value>&m2);
template<typename T>

vector<T> Sqr(const vector<T>v)
{
    vector<T>v_rez;
    for(const auto&i:v)
    {
        v_rez.push_back(Sqr(i));
    }
    return v_rez;
}

template<typename First,typename Second>
pair<First,Second>Sqr(const pair<First,Second>&p)
{
    return {Sqr(p.first),Sqr(p.second)};
}

template<typename Key,typename Value>
map<Key,Value>Sqr(const map<Key,Value>&m)
{
    map<Key,Value>rez;
    for(auto &i:m)
    {
        rez[i.first]=Sqr(i.second);
    }
    return rez;
}

template<typename Collection>
Collection Sqr(Collection x)
{
    return x*x;
}

int main()
{
    vector<int> v = {1,2,3};
    cout << "vector:";

    for (int x : Sqr(v))
    {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs
    {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs))
    {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
