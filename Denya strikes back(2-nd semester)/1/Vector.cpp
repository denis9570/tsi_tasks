#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int sum(vector <int> v);
float aver(vector <int> v);
vector <int> generateVector(int count);

typedef unsigned uint;

int main()
{
	vector<int> v;
	int i;
	cout << "enter Vector value 10 times " << endl;
	for (i = 0; i < 10; i++){
		int a;
		cin >> a;
		v.push_back(a);

	}

	cout << "Vector ";
	for (unsigned i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it;

	cout << "Vector ";
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
	cout << "-------------\n";
	cout << "sum= " << sum(v) << endl;
	cout << "aver= " << aver(v) << endl;
	cout << "-------------\n";
	cout << endl;

	vector<int> vg;
	vg = generateVector(10);
	cout << "generated vector = ";
	for (uint i = 0; i < vg.size(); i++){
		cout << vg[i] << " ";
	}



	system("pause");
	return 0;
}

int sum(vector <int> v)
{
	int sum = 0;
	for (uint i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	return sum;
}

float aver(vector <int> v){
	return sum(v) / (float)v.size();
}

vector <int> generateVector(int count){
	vector<int> n;

	srand(time(NULL));

	for (int i = 0; i < count; i++)
	{
		int g = rand() %100 + 1;
		n.push_back(g);	}
	return n;
}
