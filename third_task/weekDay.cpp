#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main()
{
	printf("Hi. Please, enter week day number: \n");

	int dayNumber;
	cin >> dayNumber;

	if	(dayNumber == 1) {
		cout << "Monday" << endl;
	} else if (dayNumber == 2) {
		cout << "Tuesday" << endl;
	} else if (dayNumber == 3) {
		cout << "Wednesday" << endl;
	} else if (dayNumber == 4) {
		cout << "Thursday" << endl;
	} else if (dayNumber == 5) {
		cout << "Friday" << endl;
	} else if (dayNumber == 6) {
		cout << "Saturday" << endl;
	} else if (dayNumber == 7) {
		cout << "Sunday" << endl;
	} else {
		cout << "pridurok bleatj, est vsego 7-m dnej nedeli, suka neobrazovanaja" << endl;
	}
		

	return 0;
}
