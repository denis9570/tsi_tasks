#include <iostream>
#include <math.h>
using namespace std;

// this code is distributed under the GNU GPL license

const int SIZE = 10;

int main()
{
    // Найти количество элементов массива, меньших С.
    
    // filling an array with random numbers
    
    srand(time(NULL));
    
    int elements[SIZE];
    for (int idx = 0; idx < SIZE; ++idx) {
        elements[idx] = rand() % 100;
    }
    
    for (int idx = 0; idx < SIZE; ++idx) {   
        cout << "elements[" << idx << "] " << elements[idx] << endl;
    }
    
    // requiring input from user
    
    int c;
    cout << "please enter any number" << endl;
    cin >> c;
    
    int result_count = 0;
    
    // counting matching elements
    
    for (int idx = 0; idx < SIZE; ++idx) {
        int current_element = elements[idx];
        
        if (current_element < c) {
            ++result_count;
        }
    }
    
    // outputing result
    
    cout << "This is the count of elements that are less than your number:" << result_count << endl;
    
        
    return 0;
}
