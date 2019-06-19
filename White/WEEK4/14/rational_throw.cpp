#include <iostream>
#include <exception>
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

		if (b == 0)
			throw invalid_argument("invalid_argument");

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

Rational operator/(const Rational& e1, const Rational& e2)
{
	int p = e1.Numerator() * e2.Denominator();
	int q = e1.Denominator() * e2.Numerator();
	
	if (q == 0)
		throw domain_error("domain_error");

	return { p,q };
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
