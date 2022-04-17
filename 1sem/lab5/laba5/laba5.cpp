#include <ctime>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <locale.h>


int main() {
	const int N=100;
	int n;
	std::cout << "Input size massiv = ";
	std::cin >> n;
	int A[N];
	int min, l, m, sum,k,sum1;
	std::cout << "Input 0 if you want input with keyboard or 1 if you want with random: ";
	std::cin >> l;
	while (l < 0 || l>1) {
		std::cout << "Input 0 if you want input with keyboard or 1 if you want with random: ";
		std::cin >> l;
	}
	switch (l){
	case 0: 
		std::cout << "Input array: " << std::endl;
		for (m = 0; m < n; m++) {
			std::cin >> A[m];
		}
		min = A[0];
		k = 0;
		sum = 0;
		sum1 = 0;
		for (m = 0; m < n; m++) {
			if (A[m] < min)
			{
				min = A[m]; 
				k = m;
			}
		}
		for (m = 0; m < k; m++) {
			sum += A[m];
		}
		std::cout << std::endl << "Summa = " << sum;

		break;
	case 1:
		srand(time(NULL));
		for (m = 0; m < n; m++) {
			A[m] = rand()%100+1;
			std::cout << A[m] << std::endl;
		}
		min = A[0];
		k = 0;
		sum = 0;
		for (m = 0; m < n; m++) {
			if (A[m] < min)
			{
				min = A[m];
				k = m;
			}
		}
		for (m = 0; m < k; m++) {
			sum += A[m];
		}
		std::cout << std::endl << "Summa = " << sum;
		break;
	}
	return 0;
}
