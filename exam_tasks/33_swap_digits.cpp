#include<iostream>
using namespace std;

// this code is distributed under the GNU GPL license

int main() 
{
	/*
	* вести двузначное число a. ѕомен¤ть цифры
	* числа местами использу¤ математические
	* операции
	*/
	
    int a;
    cout << "Enter your two-digit number" << endl;
    cin >> a;
    
    int last_digit = a % 10,
        first_digit = a / 10;
        
    cout << last_digit << first_digit << endl; 
    
    return 0;

}  
