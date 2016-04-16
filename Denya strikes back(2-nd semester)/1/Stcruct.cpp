#include <iostream>
using namespace std;

struct animal
{
	char animal_code[10];
	char animal_name[25];
	int food;
};

int main()
{
	int n;
	cout << "Enter animal numbers: ";
	cin >> n;

	animal *Animal = new animal[n];



	for (int i = 0; i<n; i++)
	{
		cout << "Enter Animal Code: ";
		cin >> Animal[i].animal_code;
		cout << "Enter Animal Name: ";
		cin >> Animal[i].animal_name;
		cout << "Enter food(kg): ";
		cin >> Animal[i].food;

		cout << "--------------------------------------" << endl;
		cout << Animal[i].animal_code << " ";
		cout << Animal[i].animal_name << " ";
		cout << Animal[i].food << " " << endl;
		cout << "--------------------------------------" << endl;

	}
	int id = 0;
	int MAX = Animal[0].food;
	for (int i = 1; i<n; i++)
	{
		if (MAX<Animal[i].food)
		{
			id = i;
			MAX = Animal[i].food;
		}
	}
	cout << "Eat the most: " << Animal[id].animal_name << endl;


	
	return 0;
}
