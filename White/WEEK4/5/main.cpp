#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

int main()
{
	ifstream input( "input.txt" );
	ofstream output("output.txt");
	if (input)
	{
		string line;
		while (getline(input, line))
		{
			cout << line << endl;
			//input.ignore(1, '\n');
		}
	}

	if (input)
	{
		string line;
		while (getline(input, line))
		{
			output << line << endl;
	//		input.ignore(1, '\n');
		}
	}
	return 0;
}