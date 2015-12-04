#include<iostream>
#include<stdlib.h>
using namespace std;

const int N = 10;

//  This code is distributed under the GNU GPL license

//  Преобразовать массив таким образом, чтобы сначала располагались все элементы, отличающиеся от максимального не более чем на 20%, а потом - все остальные. 
int main()
{
    int *arr = new int[N];
    int max;

    for (int i = 0; i < N; ++i){ // probeganue po massivu
        arr[i] = rand() % 100; // zapolnenie massiva randomnimi cislami
    }

    for(int i = 0; i < N; ++i){ // bleayj ebanij c++ tut cto bi visvesti massiv nado suka snove po nemu probezatsa blatj suka
        cout << "This is your array:" << arr[i] << endl; // vivod elementa massiva :)
    }
    
    max = arr[0]; // nacinaem s maksimalnogo znacenija massiva ravnomu 1-mu elementu massiva
    for( int i = 1; i < N; ++i){ // nacinaem so 2-go elementa massiva
       if(arr[i] > max){ // esli tekusij element massiva > maksimalnogo
            max = arr[i]; // to max prevrasaetsa v tekusij element massiva
       }
    }    
        
    cout << "This is the max element in your array:" << max << endl;

    float top_lim = max + max * 0.2; //  cisla kotorie mense top lima
    float bot_lim = max - max * 0.2; // i bolse bot lima otlicausta ot max mense cem na 20 %
        
    int *arr_like_max = new int[N]; 
    int k = 0;
    int *arr_rest = new int [N];
    int j = 0;

    for (int i = 0; i < N; ++i){ 
        if(arr[i] < top_lim && arr[i] > bot_lim){ // esli tekusij element nahoditsa mezdu top lim i bot lim 
            arr_like_max[k++] = arr[i]; // dobavitj element v arr_like_max
        } else { // ina4e
            arr_rest[j++] = arr[i]; // dobavitj v arr_rest
        }
    } 
    
    cout << "This is numbers that differ less than 20%: ";

    for (int i = 0; i < k; ++i){
     
       cout << arr_like_max[i] << ",";
    }

    cout << endl;

    cout << "This is numbers that differ more than 20%:"; 

    for (int i = 0; i < j; ++i){
        cout << arr_rest[i] << ",";
    }
    cout << endl << endl;    
        
    
    free(arr);
    return 0;
}
