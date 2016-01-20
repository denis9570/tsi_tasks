#include <iostream>
using namespace std;

// this code is distributed under the GNU GPL license

int main()
{
    /* Вводится натуральное число. Определить количество цифр 3 в нем.
    Эта программа написана для Рижского института транспорта и связи студентом Денисом Орловом(А.К)*/

    
    int a;
    cout << "Please enter random number" << endl;
    cin >> a;
    
    int count_of_three = 0;
    
    while(a > 0) {
        
        if (a % 10 == 3) {
            ++count_of_three;
        }
        
        a = a / 10;
    }
    
    cout << "This is the count of 3 in the number entered by you:" << count_of_three << endl;
    
    return 0;
}

