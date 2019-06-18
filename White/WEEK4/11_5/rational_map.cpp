#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		int a = abs(numerator);
		int b = abs(denominator);

		while (a > 0 && b > 0)
		{
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}

		p = numerator / (a + b);
		q = denominator / (a + b);

		if (q < 0 && p > 0 || q < 0 && p < 0)
		{
			q = -1 * q;
			p = -1 * p;
		}

		if (p == 0)
			q = 1;
	}

	int Numerator() const {
		return p;
	}

	int Denominator() const {
		return q;
	}

private:
	int p;
	int q;
};

bool operator==(const Rational& e1, const Rational& e2)
{
	if (e1.Numerator() == e2.Numerator() && e1.Denominator() == e2.Denominator())
		return true;
	return false;
}

bool operator < (const Rational& e1, const Rational& e2)
{ 
	const int lhs_num = e1.Numerator() * e2.Denominator(); 
	const int rhs_num = e2.Numerator() * e1.Denominator(); 
	return lhs_num < rhs_num;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
