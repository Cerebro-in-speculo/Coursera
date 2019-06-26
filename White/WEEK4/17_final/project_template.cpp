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
  
  bool DeleteEvent(const Date& date, const string& event)
  {
	  for (int k = 0; k < base[date].size(); ++k)
	  {
		  if (base[date][k] == event)
		  {
			  base[date][k].erase();
			  return true;
		  }
	  }
	  return false;
  }

  int  DeleteDate(const Date& date)
  {
	  int count = 0;
	  for (auto& i : base[date])
	  {
		  i.erase();
		  ++count;
	  }
	  return count;
  }
  //Date& Find(const Date& date) const;
  
  void Print() const
  {
	  for (const auto & i : base)
	  {
		  for (int k = 0; k < i.second.size(); ++k)
		  {
			  cout << setw(4) <<setfill('0')<< i.first.GetYear() << "-"
				   << setw(2) <<setfill('0')<< i.first.GetMonth() << "-"
				   << i.first.GetDay() << ' ';
			  cout << i.second[k] << endl;
		  }
	  }
  }

private:
	map<Date, vector<string>>base;
};

Date correctDate(const string& date)
{
	stringstream stream(date);
	int year, month, day;

	if (stream >> year && stream.peek() == '-')
		stream.ignore(1);
	else
		throw runtime_error ("Wrong date format: " + date);
	if (stream >> month && stream.peek() == '-')
		stream.ignore(1);
	else
		throw runtime_error("Wrong date format: " + date);
	if (stream >> day)
		stream.ignore(1);
	else
		throw runtime_error("Wrong date format: " + date);

	if (month < 1 || month>12)
		throw runtime_error("Month value is invalid : "+ month);

	if (day < 1 || day>31)
		throw runtime_error("Day value is invalid: " + day);
	return { year,month,day };
}

int main() {
  Database db;
    
  string command;
  while (getline (cin, command,' ')) {
	  if (command == "Add")
	  {
		  string date, event;
		  cin >> date >>event;
		  try {
			  db.AddEvent(correctDate(date), event);
			  cin.ignore(1);
		  }
		  catch (exception& ex) {
			  cout << ex.what() << endl;
			  break;
		  }
      }
	  else if (command == "Del")
	  {
		  string date, event;
		  cin >> date;

		  if (cin>>event)
		  {
			  if (db.DeleteEvent(correctDate(date), event))
				  cout << "Deleted successfully" << endl;
			  else
				  cout << "Event not found" << endl;
		  }
		  else
			  cout << "Deleted " << db.DeleteDate(correctDate(date)) << " events" << endl;
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