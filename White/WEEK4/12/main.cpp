#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;

struct  Date
{
	int day;
	int month;
	int year;
};

Date parseDate(const string& s)
{
	stringstream stream(s);
	Date date;

	stream >> date.year;
	if (stream.peek() != '/')
	{
		throw exception();
	}

	stream.ignore(1);
	stream >> date.month;
	if (stream.peek() != '/')
	{
		throw exception();
	}

	stream.ignore(1);
	stream >> date.day;
	if (stream.peek() != '/')
	{
		throw exception();
	}

	return date;
}

int main()
{
	string date_str="2017/01/25";
	Date date = parseDate(date_str);
	cout << setw(2) << setfill('0') << date.day << '.' <<
		    setw(2) << setfill('0') << date.month << '.' <<
		    setw(2) << setfill('0') << date.year << endl;

	return 0;
}