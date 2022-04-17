
#include <iostream>
using namespace std;


double simple(double x0, double x, double a, double eps) {
    do
    {
        x = x0;
        x0 = 0.5 * (x0 + a / x0);
    } while (fabs(x - x0) > eps);
    return x;
}

double recursion(double x0, double x, double a, double eps) {
    if (fabs(x - x0) < eps)
    {
        return x0;
    }

    x = x0;
    x0 = 0.5 * (x0 + a / x0);

    return recursion(x0,x,a,eps);

}

int main()
{   
    double a, x, eps = 0.000000001;

    cout << "Input a: ";
    cin >> a;

    double x0 = 0.5 * (1 + a);
    x = 0;

    cout << "Simple X = " << simple(x0, x, a, eps) << endl;
    cout << "Recursion X = " << recursion(x0, x, a, eps);

    return 0;
}