#include<iostream>
#include<math.h>
using namespace std;

// this code is distributed under the GNU GPL license

/** @param a,b,c - sides 
 * @return angle between a and b in PI * radians */
float get_angle(float a, float b, float c)
{
    // based on cosine law
    float alpha = acos((c*c - a*a - b*b) / (-2*a*b));
    
    return alpha / M_PI;
}

int main() 
{
    /*Даны действительные положительные числа
    x,y,z. Выяснить, существует ли треугольник с
    длинами сторон x,y,z . Если треугольник
    существует, то ответить - является ли он
    остроугольным*/
    
    float x, y, z;
    cout << "enter triangle sides" << endl;
    cin >> x >> y >> z;
    
    if (x >= y+z) {
        cout << "can't: x is too large" << endl;
    } else if (y >= x + z){
        cout << "can't: y is too large" << endl;
    } else if ( z >= x + y){
        cout << "can't: z is too large" << endl;
    } else {
        cout << "triangle exists" << endl;
        
        cout << "gonna check whether it is sharp agled triangle" << endl;
        
        float xy_angle = get_angle(x, y, z);
        float zy_angle = get_angle(z, y, x);
        float zx_angle = get_angle(z, x, y);
        
        cout << "angles: " << xy_angle << " " << zy_angle << " " << zx_angle << endl;
        
        if (xy_angle < 0.5 && zy_angle < 0.5 && zx_angle < 0.5){
            cout << "Yes, triangle is sharp-angled" << endl;    
        } else {
            cout << "No, triangle is not sharp-angled" << endl;
        }       
    }
    
    return 0;

}  
