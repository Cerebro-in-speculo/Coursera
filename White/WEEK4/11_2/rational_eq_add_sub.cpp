#include <iostream>
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

bool operator==( const Rational& e1,  const Rational& e2)
{
	if (e1.Numerator() == e2.Numerator() && e1.Denominator() == e2.Denominator())
		return true;
	return false;
}

Rational operator+(const Rational& e1, const Rational& e2)
{
	return Rational{ e1.Numerator()*e2.Denominator()+e2.Numerator()*e1.Denominator(),e1.Denominator()*e2.Denominator() };
}

Rational operator-( const Rational& e1,  const Rational& e2)
{
	return Rational{ e1.Numerator() * e2.Denominator() - e2.Numerator() * e1.Denominator(),e1.Denominator() * e2.Denominator() };
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
