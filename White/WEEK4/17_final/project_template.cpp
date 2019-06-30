#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<iomanip>
#include<sstream>

using namespace std;

class Date {
public:
	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	int GetDay() const { return day; }

	Date(const string& date){
		istringstream stream(date);
		int new_year, new_month, new_day;

		if (stream >> new_year && stream.peek() == '-')
		{
			stream.ignore(1);
			year = new_year;
		}
		else throw runtime_error("Wrong date format: " + date);
		if (stream >> new_month && stream.peek() == '-')
		{
			stream.ignore(1);
			month = new_month;
		}
		else throw runtime_error("Wrong date format: " + date);
		if (stream >> new_day&&stream.eof())
			day = new_day;
		else throw runtime_error("Wrong date format: " + date);

		if (new_month < 1 || new_month>12)
			throw runtime_error("Month value is invalid: " + to_string(new_month));
		if (new_day < 1 || new_day>31)
			throw runtime_error("Day value is invalid: " + to_string(new_day));
	}
private:
	int year;
	int month;
	int day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.GetYear() == rhs.GetYear())
	{
		if (lhs.GetMonth() == rhs.GetMonth())
		{
			if (lhs.GetDay() < rhs.GetDay())
				return true;
			else
				return false;
		}
		else
		{
			if (lhs.GetMonth() < rhs.GetMonth())
				return true;
			else
				return false;
		}
	}
	else
	{
		if (lhs.GetYear() < rhs.GetYear())
			return true;
		else
			return false;
	}
}

class Database {
public:
  void AddEvent(const Date& date, const string& event)
  {
		base[date].insert(event);
  }
  
  bool DeleteEvent(const Date& date, const string& event)
  {
	  if (base.count(date) != 0)
	  {
		  if (base.at(date).count(event) > 0)
		  {
			  base.at(date).erase(event);
			  return true;
		  }
	  }
	  return false;
  }

  int  DeleteDate(const Date& date)
  {
	  int value = 0;
	  if (base.count(date)>0)
	  {
		  value = base.at(date).size();
		  base.erase(date);
	  }
	  return value;
  }

  void Find(const Date& date) const
  {
	  if (base.count(date) > 0)
	  {
		  for (const auto& i : base.at(date))
			  cout << i << endl;
	  }
  }
  
  void Print() const
  {
		for(const auto &i:base)
		{
			for (const string& j : i.second)
			{
				cout <<fixed<< setfill('0') 
					<< setw(4) << i.first.GetYear() << "-"
					<< setw(2)<<i.first.GetMonth() << "-"
					<< setw(2)<< i.first.GetDay() <<" "
				    << j << endl;
			}
		}
  }

private:
	map<Date, set<string>>base;
};

int main() {

try {
  Database db;
    
  string command;
  while (getline(cin, command))
  {
	  if (command.empty()) {
		  continue;
	  }
	  istringstream stream(command);
	  command.clear();
	  stream >> command;
	  if (command == "Add")
	  {
		  string date, event;
		  stream >> date >> event;

		  Date date_temp(date);
		  db.AddEvent(date_temp, event);
	  }
	  else if (command == "Del")
	  {
		  string date, event;
		  stream >> date >> event;
		  Date date_temp(date);

		  if (!event.empty())
		  {
			  if (db.DeleteEvent(date_temp, event))
				  cout << "Deleted successfully" << endl;
			  else
				  cout << "Event not found" << endl;
		  }
		  else
			  cout << "Deleted " << db.DeleteDate(date_temp) << " events\n";
	  }
	  else if (command == "Find")
	  {
		  string date;
		  stream >> date;

		  Date date_temp(date);
		  db.Find(date_temp);
	  }
	  else if (command == "Print")
	  {
		  db.Print();
	  }
	  else
	  {
		  throw runtime_error("Unknown command: " + command);
	  }
  }
 }
catch (exception& ex) {
	cout << ex.what() << endl;
}
  return 0;
}