#include<cstdlib>
#include <iostream>
#include<cmath>
#include <algorithm>
#include <time.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int i, j, n, m, b;
    cout << "Введите N строк: ";
    cin >> n;
    cout << "Введите M столбцов: ";
    cin >> m;
    double** a;
    a = new double* [n];
    for (i = 0; i < n; i++) {
        a[i] = new double[m];
    }
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 100;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < n - 1; i++) {
        for (int k = 0; k < n - 1; k++) {
            if (a[k][0] > a[k + 1][0]) {
                for (j = 0; j < n; j++) {
                    swap(a[k][j], a[k + 1][j]);
                }
            }
        }
    }

    cout << endl << endl << "Отсортированная матрица: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    delete[]a;
    return 0;
}