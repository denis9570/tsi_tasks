#include<iostream>
#include<math.h>
using namespace std;
int main()
{   
    //ѕрограмма складывает, вычитает,возводит в степень и вычитает корень
	cout << "Enter number 1 > ";
	float a;
	cin >> a;
    cout << "Enter number 2 > ";
	float b;
	cin >> b;
	float res = a + b;
	cout << "The answer " << " is " << res << endl;


	cout << "Enter number 3 > ";
	float c;
	cin >> c;
	cout << "Enter number 4 > ";
	float d;
	cin >> d;
	float des = c - d;
	cout << "The answer " << " is " << des << endl;


	cout << "Enter number 5 > ";
	float p;
	cin >> p;
	cout << "Enter number 6 > ";
	float g;
	cin >> g;
	float les = p*g;
	cout << "square of " << p << " is " << les << endl;

	cout << "Enter number 7 > ";
	float o;
	cin >> o;
	float mes = sqrt(o);
	cout << "square root of " << o << " is " << mes << endl;

	

	




	
    system("PAUSE");
	return 0;


}

