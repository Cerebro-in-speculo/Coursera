#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int main()
{
	vector<int> t{ -8,-7,3 };
	int sum = 0;
	for (auto i : t)
	{
		sum += i;
	}
	int avg= sum / t.size();
	cout << avg << endl;

	int x = 2'000'000'000;
	cout << x << endl;
	x *= 2;
	cout << x << endl;

	cout << sizeof(int16_t) << endl;
	cout << numeric_limits<int>::min() << endl;
	cout << numeric_limits<int>::max() << endl;

	vector<int>v{ 2,3,4 };
	for (size_t i = 0; i + 1 < v.size(); ++i)
		cout << i << ":" << v[i] << endl;;

	return 0;
}