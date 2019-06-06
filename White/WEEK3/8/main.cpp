#include <iostream>

using namespace std;

class ReversibleString{
    string s;
public:

    ReversibleString(){}

    ReversibleString(const string s1):s(s1)
    {}

    void Reverse()
    {
        string temp;
        for(int k=s.length()-1;k>=0;--k)
        {
            temp+=s[k];
        }
        s=temp;
    }

    string ToString()const
    {
        return s;
    }
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
