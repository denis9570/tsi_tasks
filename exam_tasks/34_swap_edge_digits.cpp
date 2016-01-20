#include<iostream>
using namespace std;

// this code is distributed under the GNU GPL license

int main() 
{
	
	// Ввести трехзначное число a. Поменять крайние цифры числа местами
    int a;
    cout << "Enter your third-digit number" << endl;
    cin >> a;
    
    int last_digit = a % 10,
        first_two_digits = a / 10,
        reverse_two_digits  = first_two_digits % 10,
        third_two_digits = first_two_digits / 10;
        
        
        
        
    cout << last_digit << reverse_two_digits << third_two_digits <<  endl; 
    
    return 0;

} 