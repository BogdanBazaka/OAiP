#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Out_Rez(double x, double y, double S, double q)
{

	cout << setw(3) << x << setw(14) << y << setw(20) << S << setw(27) << q << endl;

}

void QQ(double x, double y, double s) {
	double q = 0;
	q = fabs(y - s);
	Out_Rez(x, y, s, q);
}

double YY(double x) {
	double y;
		y = -0.5 * log(1 - 2 * x * 0.5 + x * x);
	return y;
}

int main()
{
	int n, k;
	double a=0.1,b = 1, h = 0.1, x = 0, s = 0, q, y;
	cout << "Enter n = ";
	cin >> n;
	x = a;
	cout << setw(4) << "x " << setw(12) << "Y(x) " << setw(18) << "S(x) " << setw(30) << "|Y(x) - S(x)| " << "\n";
	while (x < b)
	{
		double q, s, p;
		s = 0;
		q = 0;
		y = YY(x);//y(x)
		for (long k = 1; k < n; k++)
		{
			p = pow(x, k) * cos(k * 3.141592 / 3) / k;
			s += p;//s(x)
		}
		QQ(x, y, s);
		s = 0;
		x += h;
	}
	return 0;
}