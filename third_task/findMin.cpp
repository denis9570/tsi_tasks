#include<stdio.h>
#include<iostream>

using namespace std;

// Вводятся числа a и b. Найти сумму таких чисел в диапазоне [a;b], которые при возведении в квадрат превышают b.
// Vvodyatsya chisla a i b. Nayti summu takikh chisel v diapazone [a;b], kotoryye pri vozvedenii v kvadrat prevyshayut b.

int main()
{
	int a, b;
	cout << "Enter a and b" << endl; 
	cin >> a >> b;
	int sum=0;
	for (int i = a; i <= b; ++i) { 
		if(i*i>b){
			sum = sum + i;
		}
	}
	cout << "sum of nubmers that are greater when squared than b is " << sum << endl; 
	
	return 0;
}
