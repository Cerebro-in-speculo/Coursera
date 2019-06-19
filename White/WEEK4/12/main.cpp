#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<exception>

using namespace std;

struct  Date
{
	int day;
	int month;
	int year;
};

void EnsureNextSymbolAndSkip(stringstream& stream)
{
	if (stream.peek() != '/')
	{
		stringstream ss;
		ss << "expectid /, but has:" << static_cast<char>(stream.peek());
		throw runtime_error(ss.str());
	}
	stream.ignore(1);
}

Date ParseDate(const string& s)
{
	stringstream stream(s);
	Date date;

	stream >> date.year;
	EnsureNextSymbolAndSkip(stream);

	stream >> date.month;
	EnsureNextSymbolAndSkip(stream);

	stream >> date.day;
	return date;
}

int main()
{
	string date_str="2017/01a25";
	try {
		Date date = ParseDate(date_str);
		cout << setw(2) << setfill('0') << date.day << '.'
			<< setw(2) << setfill('0') << date.month << '.'
			<< setw(2) << setfill('0') << date.year << endl;
	}
	catch (exception& exp)
	{
		cout << "exaption happens!" << exp.what() << endl;
	}

	return 0;
}