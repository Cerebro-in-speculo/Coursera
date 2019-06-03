#include <iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;


class Person {
public:

    string event(map<int,string>m,int year)
    {
        string rezult="empty";
        for(auto &i:m)
        {
            if(i.first<=year)
                rezult=i.second;
        }
        return rezult;
    }

    string eventHistory(map<int,string>m,vector<string>rez,int year)
    {
        vector<string>v;
        string rezult="";

        for(auto &i:m)
        {
            if(i.first<=year)
                v.push_back(i.second);
        }
        if(v.empty()||v.size()==1)
            return rezult;

        for(int k=v.size()-1;k>0;--k)
        {
            if(v[k-1]!=v[k])
                rez.push_back(v[k-1]);
        }

        if(rez.size()!=0)
        {
            for(int k=0;k<rez.size()-1;++k)
            {
                rezult+=rez[k]+", ";
            }
            rezult+=rez[rez.size()-1];
        }

        if(rezult!="")
            return " ("+rezult+")";
        else
            return rezult;
}
  void ChangeFirstName(int year, const string& first_name)
  {
        firstNameMap[year]=first_name;
  }

  void ChangeLastName(int year, const string& last_name)
  {
        lastNameMap[year]=last_name;
  }

  string GetFullName(int year)
  {
        if(event(firstNameMap,year)=="empty"&&event(lastNameMap,year)=="empty")
            return "Incognito";
        else if(event(firstNameMap,year)!="empty"&&event(lastNameMap,year)=="empty")
            return event(firstNameMap,year) + " with unknown last name";
        else if(event(lastNameMap,year)!="empty"&&event(firstNameMap,year)=="empty")
            return event(lastNameMap,year)+" with unknown first name";
        else if(event(firstNameMap,year)!="empty"&&event(lastNameMap,year)!="empty")
            return event(firstNameMap,year) +" "+ event(lastNameMap,year);
  }

 string GetFullNameWithHistory(int year)
 {
        if(event(firstNameMap,year)=="empty"&&event(lastNameMap,year)=="empty")
            return "Incognito";
        else if(event(firstNameMap,year)!="empty"&&event(lastNameMap,year)=="empty")
            return event(firstNameMap,year) +eventHistory(firstNameMap,firstNameV,year)+" with unknown last name";
        else if(event(lastNameMap,year)!="empty"&&event(firstNameMap,year)=="empty")
            return event(lastNameMap,year)+eventHistory(lastNameMap,lastNameV,year)+" with unknown first name";
        else if(event(firstNameMap,year)!="empty"&&event(lastNameMap,year)!="empty")
            return event(firstNameMap,year)+eventHistory(firstNameMap,firstNameV,year)+" "+event(lastNameMap,year)+eventHistory(lastNameMap,lastNameV,year);
 }
private:
  map<int,string>firstNameMap;
  map<int,string>lastNameMap;
  vector<string>firstNameV;
  vector<string>lastNameV;
};

int main()
{
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  return 0;
}

