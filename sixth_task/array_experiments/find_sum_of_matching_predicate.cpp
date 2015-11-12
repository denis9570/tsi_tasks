#include <iostream>
#include <math.h>
#include <stdio.h>
#include <time.h>
using namespace std;

// this code is distributed under the GNU GPL license

const int SIZE = 10;

double* make_array_simple()
{
	double* number_list = new double[SIZE];

	number_list[0] = 3;
	number_list[1] = 8;
	number_list[2] = -7;
	number_list[3] = -1;
	number_list[4] = 9;
	number_list[5] = 21;
	number_list[6] = -28;
	number_list[7] = 81;
	number_list[8] = 81;
	number_list[9] = 21;

	return number_list;
}

double* make_array_hard()
{
	srand((unsigned int)time(NULL));
    
    double* elements = new double[SIZE];
    for (int idx = 0; idx < SIZE; ++idx) {
        elements[idx] = rand() % 100 - 50;
    }

	return elements;
}

int main()
{
	cout << "This program will find the sum of all array elements after last negative" << endl;
	
	// double* number_list = make_array_simple();
	double* number_list = make_array_hard();
	
	for (int i = 0; i < SIZE; ++i) {
		double number = number_list[i];
		printf("%d\n", int(number));
	}

	int last_negative_index = -1;
	for (int i = 9; i >= 0; --i){
		double number = number_list[i];
		if( number < 0){
			last_negative_index = i;
			break;
		}
	}

	int sum = 0;
	for(int i = last_negative_index + 1; i < SIZE; ++i){
		sum = sum + number_list[i];
	}
	cout << "this is the sum of all array elements after last negative:" << sum << endl;
	
	system("PAUSE");

	main();

	return 0;
}