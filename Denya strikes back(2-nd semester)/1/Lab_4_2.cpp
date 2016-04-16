#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef unsigned uint;

void print_vector(vector<float> v);
void insert_every(vector<float> &v, int interval, float value);
vector<float> make_intervaled(vector<float> v, int interval, float value);
float sum(vector<float> v);

int main()
{
    vector<float> v;
    for( uint i = 0; i < 20; i++ ){
        float g = (double)rand() / (double)RAND_MAX;
        v.push_back(g);
    }
    print_vector(v);

    insert_every(v, 5, -0.5);
    print_vector(v);

    cout << "Sum: " << sum(v) << endl;

    for(int i = v.size() - 1; i >= 0; --i){
        if(v[i] > 0.5){
            v.erase(v.begin() + i);
        }
    }

    print_vector(v);

    sort(v.rbegin(), v.rend());
    print_vector(v);

    return 0;
}

void insert_every(vector<float> &v, int interval, float value)
{
    for (uint i = 0; i < v.size(); i += interval + 1) {
        v.insert(v.begin() + i, value);
    }
}

void print_vector(vector<float> v)
{
    cout << "Vector value: " << endl;
    for(uint i = 0; i < v.size(); i++){
         cout << v.at(i) << endl;
    }
}

float sum(vector<float> v)
{
    float sum = 0;
    for(uint i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    return sum;
}
