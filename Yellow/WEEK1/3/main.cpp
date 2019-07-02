#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int64_t>t;
	int n = 0;
	int64_t k = 0, avg = 0, total = 0;

	cin >> n;
	while (n > 0)
	{
		cin >> k;
		t.push_back(k);
		total += k;
		--n;
	}
	avg = total / static_cast<int64_t>(t.size());

	int count = 0;
	vector<size_t>max_t;
	for (size_t k = 0; k < t.size(); ++k)
	{
		if (t[k] > avg)
		{
			max_t.push_back(k);
			++count;
		}
	}
	cout << count << endl;
	for (const size_t& i : max_t)
		cout << i << ' ';
	return 0;
}