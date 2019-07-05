#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int32_t r = 0;
	cin >> r;

	int64_t w = 0, h = 0, d = 0;
	vector<uint64_t>v(n);

	while (n > 0)
	{
		cin >> w >> h >> d;
		v.push_back(w * h * d * r);
		--n;
	}
	uint64_t sum = 0;
	for (const uint64_t& i : v)
		sum += i;
	cout << sum << endl;
	return 0;
}