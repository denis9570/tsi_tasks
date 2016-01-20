#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

float f1(float x) 
{
	return 1/(x + 3); 
}

float f2(float x) 
{
	const float e = exp(1.0);
	return pow(e, -2 * x);
}

float f3(float x)
{
	return log(x + 5);

}

int main() 
{
	printf("Hello World!\n");

	/*for (int i = 0; i < 10; ++i) {
		printf("%d %f\n", i, f1(i));
	}*/

	float x,y;
	cout << "Enter x" << endl;
	cin >> x;
	if (x > -5 && x <= 2) {
		y = f1(x);
	} else if (x > 2 && x <= 4) {
		y = f2(x);
	} else {
		y = f3(x);
	}
	cout <<"y=" << y << endl;

	main(); // =D

	return 0;
}
