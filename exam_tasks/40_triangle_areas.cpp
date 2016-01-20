#include<iostream>
#include<math.h>
using namespace std;

// this code is distributed under the GNU GPL license

// Heron's formula
float get_area(float a, float b, float c) // �������� ���� �������
{
    float p = (a+b+c)/2; // ������������
    
    return sqrt(p*(p-a)*(p-b)*(p-c)); // ���������� ���������
}

int main() 
{
	// ���� ��� ������� ������ � ��� ������� ������� ������������. 
	// ����������, ����� �� ��� ������������ �������������, �.�. ����� �� ��� ������ �������.
	
    float a1, b1, c1;
    float a2, b2, c2;
    cout << "Enter two triangle sides (a1, b1, c1, a2, b2, c2): " << endl;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    
    float S1 = get_area(a1,b1,c1); // ������� ������� ������� ������������  
    float S2 = get_area(a2,b2,c2); // ������� ������� ������� ������������
    
    cout << "S1=" << S1 << " S2= "<< S2 << endl;
    
    if(S1 == S2){
        cout << "Yes, areas are equal";     
    } else {
        cout << "No, areas not equal";
    }
        
    
    return 0;

}  
