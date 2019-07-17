#include <iostream>
#include<map>
using namespace std;

template<typename K,typename V>
V& GetRefStrict(map<K,V>&m,K key)
{
    if(m.count(key))
        return m[key];
    else
        throw(runtime_error("error!"));
}

int main()
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue

    return 0;
}
