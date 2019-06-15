#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	ifstream input("input.txt");
	int line;
	int row;

	input >> line >> row;

	int x;
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			input >> x;
			input.ignore(1);

			if (j < row - 1)
				cout << setw(10)<< x << ' ';
			else
				cout << setw(10) << x;
		}
		if(i<line-1)
			cout << endl;
	}

	return 0;
}