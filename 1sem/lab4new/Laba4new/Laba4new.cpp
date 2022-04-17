
#include <iostream>
#include <cmath>
using namespace std;
typedef double (*TFun)(double);  // Декларация типа указателя на функцию
double fun1(double);   // Декларации прототипов функций
double fun2(double);
double fun3(double);
void Out_Rez (TFun,double,double,double);

void main() {
    setlocale(LC_ALL, "Russian");
double a, b, h; puts("Введите a,b,h");
cin >> a >> b >> h;
puts("\n\t Функция - 2*exp(x)");
Out_Rez (fun1,a,b,h);
puts("\n\t Функция - sin(x)*sin(x)");
Out_Rez (fun2,a,b,h);
puts("\n\t Функция - |Y - S|");
Out_Rez(fun3, a, b, h);
puts("\n Нажмите любую кнопку для завершения ... ");
 }

//---------- Реализации функций пользователя --------------------------------- 

double fun1( double r){
    return 2*exp(r*r);
}

double fun2(double r) {
    return pow(sin(r), 2);
}

double fun3(double r){
    return;
}

void Out_Rez (TFun f,double xn,double xk,double h) {
    for (double x = xn; x <= xk; x += h) {
        cout << "x = " << x << ", " << "y = " << f(x) << endl;
    }
}