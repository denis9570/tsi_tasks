#include<iostream>
#include<math.h>
using namespace std;
int main()

{
	//программа возводит число а в степень b
    cout << "Enter number 1 > ";
	float a;
	cin >> a;
	cout << "Enter number 2 > ";
	float b;
	cin >> b;
	float res = pow(a, b);
	cout << "Pow" << " is " << res << endl;
	system("PAUSE");
	return 0;
	


}