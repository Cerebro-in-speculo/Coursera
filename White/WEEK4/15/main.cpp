#include <iostream>
#include<sstream>

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
		{
			throw runtime_error ("Invalid argument");
		}

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

Rational operator+(const Rational& e1, const Rational& e2)
{
	return Rational{ e1.Numerator() * e2.Denominator() + e2.Numerator() * e1.Denominator(),e1.Denominator() * e2.Denominator() };
}

Rational operator-(const Rational& e1, const Rational& e2)
{
	return Rational{ e1.Numerator() * e2.Denominator() - e2.Numerator() * e1.Denominator(),e1.Denominator() * e2.Denominator() };
}

Rational operator*(const Rational& e1, const Rational& e2)
{
	return { e1.Numerator() * e2.Numerator(),e1.Denominator() * e2.Denominator() };
}

Rational operator/(const Rational& e1, const Rational& e2)
{
	int p = e1.Numerator() * e2.Denominator();
	int q = e1.Denominator() * e2.Numerator();

	if (q == 0)
		throw runtime_error ("Division by zero");

	return { p,q };
}

ostream& operator<<(ostream& stream, const Rational& output)
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

bool operator < (const Rational& e1, const Rational& e2)
{
	const int lhs_num = e1.Numerator() * e2.Denominator();
	const int rhs_num = e2.Numerator() * e1.Denominator();
	return lhs_num < rhs_num;
}

int main() {
	try {
		string s1,s2;
		char c;
		cin >> s1 >> c >> s2;

		istringstream input1(s1);
		istringstream input2(s2);

		Rational r1, r2;

		input1 >> r1;
		input2 >> r2;
		
		if (c == '*')
			cout << r1 * r2 << endl;
		if (c == '/')
			cout << r1 / r2 << endl;
		if (c == '+')
			cout << r1 + r2 << endl;
		if (c == '-')
			cout << r1 - r2 << endl;
	}
	catch (exception& ex)
	{
		cout<<ex.what();
	}

	return 0;
}
