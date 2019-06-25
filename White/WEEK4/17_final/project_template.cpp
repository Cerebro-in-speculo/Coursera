#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
#include<sstream>

using namespace std;

class Date {
public:
	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	int GetDay() const { return day; }

	Date(int p_year=0,int p_month=0,int p_day=0):year(p_year),month(p_month),day(p_day){}

private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() > rhs.GetYear())
		return true;
	else if (lhs.GetYear() >= rhs.GetYear() && lhs.GetMonth() > rhs.GetMonth())
		return true;
	else if (lhs.GetYear() >= rhs.GetYear() && lhs.GetMonth() >= rhs.GetMonth() && lhs.GetDay() > rhs.GetDay())
		return true;
	else return false;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event)
  {
	  base[date].push_back(event);
  }
  
  //bool DeleteEvent(const Date& date, const string& event);
  //int  DeleteDate(const Date& date);
  //Date& Find(const Date& date) const;
  
  void Print() const
  {
	  char ch = '-';
	  for (const auto & i : base)
	  {
		  for (int k = 0; k < i.second.size(); ++k)
		  {
			  cout << setw(4) <<setfill('0')<< i.first.GetYear() << ch
				   << setw(2) <<setfill('0')<< i.first.GetMonth() << ch
				   << i.first.GetDay() << ' ';
			  cout << i.second[k] << endl;
		  }
	  }
  }

private:
	map<Date, vector<string>>base;
};

int main() {
  Database db;
    
  string command;
  while (getline(cin, command,' ')) {
	  if (command == "Add")
	  {
		  string date,event;
		  cin >> date >>event;
		  
		  stringstream stream(date);
		  int year, month, day;

		  if (stream >> year&&stream.peek()=='-')
			  stream.ignore(1);
		  else
		  {
			  cout << "Wrong date format: " + date;
			  break;
		  }
		  if (stream >> month &&stream.peek() == '-')
			  stream.ignore(1);
		  else 
		  {
			  cout << "Wrong date format: " + date;
			  break;
		  }
		  if (stream >> day)
		  {
			  stream.ignore(1);
		  }
		  else 
		  {
			  cout << "Wrong date format: " + date;
			  break;
		  }

		  if (month < 1 || month>12)
		  {
			  cout << "Month value is invalid : " << month;
			  break;
		  }
		  if (day < 1 || day>31)
		  {
			  cout << "Day value is invalid: " << day;
			  break;
		  }
				
			  db.AddEvent({ year,month,day }, event);
      }
	  else if (command == "Del")
	  {
	  }
	  else if (command == "Find")
	  {
	  }
	  else if (command == "Print")
	  {
		  db.Print();
	  }
	  else
	  {
		  cout << "Unknown command :" + command;
		  break;
	  }
  }

  return 0;
}