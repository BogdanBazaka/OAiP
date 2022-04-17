#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef double (*TFun)(double);
double fun1(double h) { //Y
	double x, a = 0.1,b=1,y;
	x = a;
	for (; x <= b; x += h) {
		y = -0.5 * log(1 - 2 * x * 0.5 + x * x);
		cout << setw(4) << "Y(x) = " << y << endl;
	}
	return y;
}
double fun2(int n) { //S
	double a = 0.1, b = 1.0, x, s =0, h = 0.1;
	x = a;
	do {
		for (int k = 1; k <= n; k++) {
			s += (pow(x, k) * cos((k * 3.141592) / 3)) / k;
		}
		cout << setw(35) << "S(x) = " << s << endl;
		s = 0;
		x += h;

	} while (x <= b);
	return s;
}
double module(double a) {
	double b = 1.0, h = 0.1, n = 10, x, s = 0, k, y = 0, m;
	x = a;
	do {
		for (k = 1; k <= n; k++) {
			y = -0.5 * log(1 - 2 * x * 0.5 + x * x);
			s += pow(x, k) * cos(k * 3.141592 / 3) / k;
			m = fabs(s - y);
		}
		cout << setw(60) << "module = " << m << endl;
		s = 0;
		x += h;
	} while (x <= b);
	return m;

}

int main() {
	fun1(0.1);
	cout << endl;
	fun2(3000);
	cout << endl;
	module(0.1);
	cout << endl;

	return 0;
}