#include <iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;


class Person {
public:

    Person(const string&firstName,const string&lastName,const int& ageYear)
    {
        age=ageYear;
        firstNameMap[ageYear]=firstName;
        lastNameMap[ageYear]=lastName;
    }

    string event(const map<int,string>m,const int year)const
    {
        string rezult="empty";

        if(year<age)
        return "No person";

        for(auto &i:m)
        {
            if(i.first<=year)
                rezult=i.second;
        }
        return rezult;
    }

    string eventHistory(const map<int,string>m,vector<string>rez,const int year)const
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
  void ChangeFirstName(const int year, const string& first_name)
  {
        if(year>age)
        firstNameMap[year]=first_name;
  }

  void ChangeLastName(const int year, const string& last_name)
  {
        if(year>age)
        lastNameMap[year]=last_name;
  }

  string GetFullName(int year)const
  {
        if(event(firstNameMap,year)=="No person")
            return "No person";
        else if(event(firstNameMap,year)=="empty"&&event(lastNameMap,year)=="empty")
            return "Incognito";
        else if(event(firstNameMap,year)!="empty"&&event(lastNameMap,year)=="empty")
            return event(firstNameMap,year) + " with unknown last name";
        else if(event(lastNameMap,year)!="empty"&&event(firstNameMap,year)=="empty")
            return event(lastNameMap,year)+" with unknown first name";
        else if(event(firstNameMap,year)!="empty"&&event(lastNameMap,year)!="empty")
            return event(firstNameMap,year) +" "+ event(lastNameMap,year);
  }

 string GetFullNameWithHistory(int year)const
 {
        if(event(firstNameMap,year)=="No person")
            return "No person";
        else if(event(firstNameMap,year)=="empty"&&event(lastNameMap,year)=="empty")
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
  int age;
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}
