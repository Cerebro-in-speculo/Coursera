#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Student {
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main()
{
	int numberOfstudents;
	int numberOfstudentRequests;
	vector<Student>students;

	cin >> numberOfstudents;
	while (numberOfstudents > 0)
	{
		Student student;
		cin >> student.name >> student.surname >> student.day >> student.month >> student.year;
		students.push_back(student);

		--numberOfstudents;
	}

	string choice;
	int numberStudent;

	cin >> numberOfstudentRequests;
	while (numberOfstudentRequests>0)
	{
		cin >> choice >> numberStudent;
		
		if (choice == "name" && numberStudent <= students.size()&&numberStudent!=0)
			cout << students[numberStudent-1].name <<" "<<students[numberStudent-1].surname << endl;
		else if (choice == "date" && numberStudent <= students.size() && numberStudent != 0)
			cout << students[numberStudent-1].day << '.' << students[numberStudent-1].month << '.' << students[numberStudent-1].year << endl;
		else
			cout << "bad request\n";

		--numberOfstudentRequests;
	}

	return 0;
}