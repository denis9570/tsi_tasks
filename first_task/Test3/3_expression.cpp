#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	// ��������� ������ ���� ������� ������ :)
	
    cout << "Enter a>";
	float a;
	cin >> a;
	cout << "Enter b>";
	float b;
	cin >> b;
    
	b = 2.0*cos(1.0 / 2.0)*(a + b)*cos(1.0 / 2.0)*(a - b);
	cout << "b=" << b << endl;
	
    system("PAUSE");
	return 0;
}