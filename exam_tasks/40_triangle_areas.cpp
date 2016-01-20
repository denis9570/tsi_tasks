#include<iostream>
#include<math.h>
using namespace std;

// this code is distributed under the GNU GPL license

// Heron's formula
float get_area(float a, float b, float c) // обьявили свою функцию
{
    float p = (a+b+c)/2; // полупериметр
    
    return sqrt(p*(p-a)*(p-b)*(p-c)); // возвращаем результат
}

int main() 
{
	// Даны три стороны одного и три стороны другого треугольника. 
	// Определить, будут ли эти треугольники равновеликими, т.е. имеют ли они равные площади.
	
    float a1, b1, c1;
    float a2, b2, c2;
    cout << "Enter two triangle sides (a1, b1, c1, a2, b2, c2): " << endl;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    
    float S1 = get_area(a1,b1,c1); // находим площадь первого треугольника  
    float S2 = get_area(a2,b2,c2); // находим площадь второго треугольника
    
    cout << "S1=" << S1 << " S2= "<< S2 << endl;
    
    if(S1 == S2){
        cout << "Yes, areas are equal";     
    } else {
        cout << "No, areas not equal";
    }
        
    
    return 0;

}  
