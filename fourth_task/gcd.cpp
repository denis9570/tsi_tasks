#include<stdio.h>
#include<iostream>

using namespace std;

// Greatest Common Divisor (Euclidean algorithm implementation)
int gcd(int a, int b)
{
	return  a == 0 ? b : gcd(b % a, a); 
}

// Least Common Multiple (logic implementation)
int lcm(int a, int b)
{
	return a * b / gcd(a, b);	
} 


int main()
{	
	int a, b;
	cout << "This program will find the greatest common divisor and the least common multiple, please enter a and b numbers " << endl;
	cin >> a >> b;

	int result_gcd = gcd(a, b);
	int result_lcm = lcm(a, b);
	cout << "this is the result of gcd " << result_gcd << endl;
	cout << "but this is the result of lcm " << result_lcm << endl;

	return 0;
}
