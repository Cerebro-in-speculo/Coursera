#include <iostream>
#include <sstream>
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

ostream& operator<<(ostream& stream,const Rational& output)
{
	stream << output.Numerator() << '/' << output.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& input)
{
	int x, y;
	stream >> x;
	stream.ignore(1);
	stream >> y;
	if (stream)
	{
		input = Rational{ x,y };
	}
	return stream;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
