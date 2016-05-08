#include<iostream>
#include<fstream>
using namespace std;

typedef unsigned uint;

struct publisher_t {
	char publisher_name[64];
	uint foundation;
	char country[64];
};

struct game_t
{
	char game_name[64];
	float price;
	publisher_t publisher;
	char platform[16];
	uint players;
	uint release_date;
	char genre[64];
	uint amount;      // amount of copies in shop storage
	
};

// for internal use
struct game_list_t {
	game_t* games = 0;
	int size = 0;
};

void add();
void show();
void delete_game();
void handle_events();
void search_menu();
game_list_t read_file_list();

int main()
{
	handle_events();
	system("pause");
	return 0;
}

void print_game_info(game_t game)
{
	
	cout << game.publisher.publisher_name << " " << game.publisher.country << " "
		<< game.publisher.foundation << endl;

	cout << game.game_name << " " << game.price << " " << game.platform << " " << game.players << " "
		<< game.release_date << " " << game.genre << " " << game.amount << endl;
	cout << endl;
}



void add()
{
	game_t game;

	cout << "Enter your game name: "; cin >> game.game_name;
	cout << "Enter game price: "; cin >> game.price;
	cout << "Enter game platform: "; cin >> game.platform;
	cout << "Enter count of players: "; cin >> game.players;
	cout << "Enter game release_date: "; cin >> game.release_date;
	cout << "Enter game genre: "; cin >> game.genre;
	cout << "Enter your game copies amount in storage: "; cin >> game.amount;

	cout << "Enter game publisher name: "; cin >> game.publisher.publisher_name;
	cout << "Enter publisher country: "; cin >> game.publisher.country;
	cout << "Enter publisher foundation year : "; cin >> game.publisher.foundation;
	
	ofstream file;
	file.open("games.dat", ios::binary | ios::app); 
	if (!file) cout << "Mistake!!!\n";
	else
	{
		file.write((char*)&game, sizeof(game_t));
		file.close();
	}
}

void delete_game()
{
	ifstream file;
	file.open("games.dat", ios::binary);
	file.seekg(0, ios::end);
	int size = file.tellg();
	size = size / sizeof(game_t);
	file.seekg(0, ios::beg);
	game_t *games = new game_t[size];
	file.read((char*)games, size * sizeof(game_t));
	file.close();
	cout << "Enter your game name, to delete it ";
	char game_name[64]; cin >> game_name;
	ofstream newfile;
	newfile.open("games.dat", ios::binary);
	for (int i = 0; i < size; i++)
	{
		if (strcmp(games[i].game_name, game_name) != 0)
			newfile.write((char*)&games[i], sizeof(game_t));
		else
		{
			print_game_info(games[i]);
			cout << "\nDo you really want to remove this game?(y/n)\n";
			char answer; cin >> answer;
			if (answer == 'n')
				newfile.write((char*)&games[i], sizeof(game_t));

		}
	}
	newfile.close();
}

void handle_events()
{
	int choice = -1;
	while (choice)
	{
		system("cls");
		cout << "\n---------MENU----------\n";
		cout << "1. Add\n2. Show\n3. Remove\n4. Search\n0. Exit\n";
		cout << "Enter your choice>";
		cin >> choice;

		switch (choice)
		{
		case 1: {
			add();

			system("pause"); break; }
		case 2: {
			show();
			system("pause"); break; }

		case 3: {
			delete_game();
			system("pause"); break; }

		case 4: {
			search_menu();
			system("pause"); break; }

		case 0: {
			cout << "See ya later!\n";
			break; }
		}
	}
}

// free memory after using it!
game_list_t read_file_list()
{
	game_list_t result;

	ifstream file;
	file.open("games.dat", ios::binary);
	if (!file) cout << "\n\nThere is some error with your file, please try again!\n\n";
	else
	{
		file.seekg(0, ios::end);
		int size = file.tellg();
		size = size / sizeof(game_t);
		file.seekg(0, ios::beg);

		game_t *games = new game_t[size];
		file.read((char*)games, size * sizeof(game_t));
		file.close();

		result.games = games;
		result.size = size;
	}

	return result;
}


void search_by_name(char game_name[64])
{
	game_list_t list = read_file_list();
	
	for (int i = 0; i < list.size; ++i) {
		if (strcmp(game_name, list.games[i].game_name) == 0) {
			cout << "the game that you requested:" << endl;
			print_game_info(list.games[i]);
		}
	}

	delete list.games;
}

void search_by_publisher(char publisher_name[64]) 
{
	game_list_t list = read_file_list();

	for (int i = 0; i < list.size; ++i) {
		if (strcmp(publisher_name, list.games[i].publisher.publisher_name) == 0) {
			cout << "the game that you requested:" << endl;
			print_game_info(list.games[i]);
		}
	}

	delete list.games;
}


void filter_by_price(float max_price) 
{
	game_list_t list = read_file_list();

	for (int i = 0; i < list.size; ++i) {
		game_t game = list.games[i];
		if (game.price <= max_price) {
			cout << "the game that you requested: " << endl;
			print_game_info(game);
		}
	}

	delete list.games;
}


void count_copies_by_publisher(char publisher_name[64])
{
	game_list_t list = read_file_list();
	int sum = 0;
	for (int i = 0; i < list.size; ++i) {
		game_t game = list.games[i];
		if (strcmp(publisher_name, game.publisher.publisher_name) == 0) {
			sum += game.amount;
		}
	
	}
	cout << "the remaining copies " << sum << endl;

	delete list.games;
}


void count_price_by_genre(char genre[64])
{
	game_list_t list = read_file_list();
	float sum = 0;
	for (int i = 0; i < list.size; ++i) {
		game_t game = list.games[i];
		if (strcmp(genre, game.genre) == 0) {
			sum += game.price * game.amount;
			
		}
	}
	cout << "your count price" << sum << endl;
	

	delete list.games;
}

// sorts {games} array
void bubble_sort_price(game_t games[], int size) 
{
	for (int j = 0; j < size; ++j) {
		for (int i = 0; i < size - 1; ++i) {
			if (games[i].price > games[i + 1].price) {
				game_t tmp = games[i];
				games[i] = games[i + 1];
				games[i + 1]= tmp;
			}
		}
	}
}

// sorts {games} array
void bubble_sort_name(game_t games[], int size)
{
	for (int j = 0; j < size; ++j) {
		for (int i = 0; i < size - 1; ++i) {
			if (strcmp(games[i].game_name, games[i + 1].game_name) > 0) {
				game_t tmp = games[i];
				games[i] = games[i + 1];
				games[i + 1] = tmp;
			}
		}
	}
}

void show()
{
	game_list_t list = read_file_list();


	for (int i = 0; i < list.size; i++) {
		print_game_info(list.games[i]);
	}
	cout << endl;
	cout << "Sorted by game name: " << endl;
	bubble_sort_name(list.games, list.size);
	cout << endl;

	for (int i = 0; i < list.size; i++) {
		print_game_info(list.games[i]);
	}

	cout << endl;
	cout << "Sorted by game price: " << endl;
	bubble_sort_price(list.games, list.size);
	cout << endl;

	for (int i = 0; i < list.size; i++) {
		print_game_info(list.games[i]);
	}


	delete list.games;
}

void search_menu()
{
	int choice = -1;
	char name[64];

	while (true)
	{
		system("cls");
		cout << "\n---------MENU----------\n";
		cout << "1.game name \n2.publisher\n3.max price\n4.copies in the storage\n5.count price\n";
		cout << "Enter your choice>";
		cin >> choice;

		switch (choice)
		{
			case 1:
				cout << "Enter game name\n";
				cin >> name;

				search_by_name(name);
				return;

			case 2:
				cout << "Enter publisher name\n";
				cin >> name;

				search_by_publisher(name);
				return;

			case 3:
				float max_price;
				cout << "Enter max price\n";
				cin >> max_price;

				filter_by_price(max_price);
				return;


			case 4:
				cout << "Enter publisher name\n";
				cin >> name;

				count_copies_by_publisher(name);
				return;

			case 5:
				char genre[64];
				cout << "Enter game genre\n";
				cin >> genre;

				count_price_by_genre(genre);
				return;

		}
	}

}

