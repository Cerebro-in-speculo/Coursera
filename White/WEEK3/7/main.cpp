#include <iostream>
#include<string>
#include<map>
#include<algorithm>

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

private:
  map<int,string>firstNameMap;
  map<int,string>lastNameMap;
};

int main() {
  Person person;

  //person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
