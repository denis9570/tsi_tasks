#include<iostream>
#include<fstream>
#include<limits>
#include <algorithm>

using namespace std;


typedef unsigned uint;

struct publisher_t {
	char publisher_name[64];
	uint foundation;
	char country[64];
	int id;
};

struct game_t
{
	char game_name[64];
	float price;
	int publisher_id;
	char platform[16];
	uint players;
	uint release_date;
	char genre[64];
	uint amount; // amount of copies in shop storage
	int id;
};

// for internal use
struct record_list_t {
	void* records = 0;
	int size = 0;
};

// for internal use
struct game_list_t {
	game_t* games = 0;
	int size = 0;
};

// for internal use
struct publisher_list_t {
	publisher_t* publishers = 0;
	int size = 0;
};

void greetings();
void add_game();
void show_publishers();
void show_games();
void delete_game();
void handle_events();
void search_menu();
game_list_t read_game_list();
publisher_list_t read_publisher_list();


// Global variables.
int last_game_id = 0;  
int last_publisher_id = 0;

int main()
{
	greetings();
	handle_events();
	system("pause");
	return 0;
}

void print_publisher_info(publisher_t publisher)
{
	cout << "\n";
	cout << "id: " << publisher.id << "\n"
		<< "Publisher: " << publisher.publisher_name << "\n" 
		<< "Country of publisher: " << publisher.country << "\n"
		<< "date of founding: " << publisher.foundation << endl;
}


void print_game_info(game_t game)
{
	cout << "id: " << game.id << "\n"
		<< "game name: " << game.game_name << "\n" 
		<< "publisher id: " << game.publisher_id << "\n"
		<< "game price($): " << game.price << "\n" 
		<< "platform: " << game.platform << "\n" 
		<< "count of players: " << game.players << "\n"
		<< "game release date: " << game.release_date << "\n" 
		<< "genre: " << game.genre << "\n" 
		<< "amount in the storage: " << game.amount << endl;
	cout << endl;
}



void greetings()
{

	cout << "Database of games version 1.0 " << endl;
	system("pause");

}

void add_publisher()
{
	publisher_t publisher;
	publisher.id = ++last_publisher_id;

	cout << "Enter game publisher name: "; cin.ignore(); cin.getline(publisher.publisher_name, 999);
	cout << "Enter publisher country: "; cin.ignore();  cin.getline(publisher.country, 999);
	cout << "Enter publisher foundation year : ";
	while (!(cin >> publisher.foundation) || publisher.foundation > 2016 || publisher.foundation < 1970) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a correct year from 1970 to 2016: ";
	}

	ofstream file;
	file.open("publishers.dat", ios::binary | ios::app);
	if (!file) cout << "Mistake!!!\n";
	else
	{
		file.write((char*)&publisher, sizeof(publisher_t));
		file.close();
	}
}

// prints the info about publisher (if any) and asks 
// user to confirm it is the publisher he wants
bool ok_publisher_id(int publisher_id)
{
	publisher_list_t list = read_publisher_list();
	bool ok_id = false;

	for (int i = 0; i < list.size; ++i) {
		publisher_t publisher = list.publishers[i];

		if (publisher_id == publisher.id)
		{
			print_publisher_info(publisher);
			ok_id = true;
		}
	}

	delete list.publishers;
	return ok_id;
}

void add_game()
{
	game_t game;
	game.id = ++last_game_id;

	cout << "Enter publisher id: "; 
	while (!(cin >> game.publisher_id) || !ok_publisher_id(game.publisher_id)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	cout << "Enter your game name: "; cin.ignore(); cin.getline(game.game_name, 999);
	cout << "Enter game price: ";
	while (!(cin >> game.price)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid price. Try again: ";
	}
	cout << "Enter game platform: "; cin.ignore(); cin.getline(game.platform, 999);
	cout << "Enter count of players: "; 
	while (!(cin >> game.players)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}
	cout << "Enter game release date: ";
	while (!(cin >> game.release_date) || game.release_date > 2016 || game.release_date < 1947) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a correct year from 1947 to 2016: ";
	}
	cout << "Enter game genre: "; cin.ignore();  cin.getline(game.genre, 999);
	cout << "Enter your game copies amount in storage: "; 
	while (!(cin >> game.amount)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input. Try again: ";
	}


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
	game_list_t list = read_game_list();

	cout << "Enter your game name, to delete it ";
	char game_name[64]; cin.ignore(); cin.getline(game_name, 64);
	ofstream newfile;
	newfile.open("games.dat", ios::binary);
	for (int i = 0; i < list.size; i++)
	{
		if (strcmp(list.games[i].game_name, game_name) != 0)
			newfile.write((char*)&list.games[i], sizeof(game_t));
		else
		{
			print_game_info(list.games[i]);
			cout << "\nDo you really want to remove this game?(y/n)\n";
			char answer;  cin >> answer;
			if (answer == 'n')
				newfile.write((char*)&list.games[i], sizeof(game_t));
		}
	}
	newfile.close();

	delete list.games;
}

void handle_events()
{
	int choice = -1;
	while (choice)
	{
		system("cls");
		cout << "\n---------MENU----------\n";
		cout << "1. Add game\n2. Show games\n3. Remove\n4. Search\n5. show publishers\n6. add publishers\n0. Exit\n";
		cout << "Enter your choice>";
		cin >> choice;

		switch (choice) {
			case -100:
			break; case 1: add_game();
			break; case 2: show_games();
			break; case 3: delete_game();
			break; case 4: search_menu();
			break; case 5: show_publishers();
			break; case 6: add_publisher();
			break; case 0: cout << "See ya later!\n";
		}

		system("pause");
	}
}

// need to free memory, after using it!
record_list_t read_record_list(char* file_name, int record_size)
{
	record_list_t result;

	ifstream file;
	file.open(file_name, ios::binary);
	if (!file) cout << "\n\nThere is some error with your file, please try again!\n\n";
	else
	{
		file.seekg(0, ios::end);
		int size = file.tellg();
		size = size / record_size;
		file.seekg(0, ios::beg);

		void* records = malloc(size * record_size);
		file.read((char*)records, size * record_size);
		file.close();

		result.records = records;
		result.size = size;
	}

	return result;
}

// need to free memory, after using it!
game_list_t read_game_list()
{
	game_list_t result;
	record_list_t records = read_record_list("games.dat", sizeof(game_t));

	result.games = (game_t*)records.records;
	result.size = records.size;

	for (int i = 0; i < result.size; ++i) {
		game_t game = result.games[i];
		last_game_id = max(last_game_id, game.id);
	}

	return result;
}

// need to free memory, after using it!
publisher_list_t read_publisher_list()
{
	publisher_list_t result;
	record_list_t records = read_record_list("publishers.dat", sizeof(publisher_t));

	result.publishers = (publisher_t*)records.records;
	result.size = records.size;

	for (int i = 0; i < result.size; ++i) {
		publisher_t game = result.publishers[i];
		last_game_id = max(last_game_id, game.id);
	}

	return result;
}


void search_by_name(char game_name[64])
{
	game_list_t list = read_game_list();

	for (int i = 0; i < list.size; ++i) {
		if (strcmp(game_name, list.games[i].game_name) == 0) {
			cout << "the game that you requested:" << endl;
			print_game_info(list.games[i]);
		}
	}

	delete list.games;
}

void search_by_publisher(int publisher_id)
{
	game_list_t list = read_game_list();

	for (int i = 0; i < list.size; ++i) {
		if (publisher_id == list.games[i].publisher_id) {
			cout << "the game that you requested:" << endl;
			print_game_info(list.games[i]);
		}
	}

	delete list.games;
}


void filter_by_price(float max_price)
{
	game_list_t list = read_game_list();

	for (int i = 0; i < list.size; ++i) {
		game_t game = list.games[i];
		if (game.price <= max_price) {
			cout << "the game that you requested: " << endl;
			print_game_info(game);
		}
	}

	delete list.games;
}


void count_copies_by_publisher(int publisher_id)
{
	game_list_t list = read_game_list();
	int sum = 0;
	for (int i = 0; i < list.size; ++i) {
		game_t game = list.games[i];
		if (publisher_id == game.publisher_id) {
			sum += game.amount;
		}

	}
	cout << "the remaining copies " << sum << endl;

	delete list.games;
}


void count_price_by_genre(char genre[64])
{
	game_list_t list = read_game_list();
	float sum = 0;
	for (int i = 0; i < list.size; ++i) {
		game_t game = list.games[i];
		if (strcmp(genre, game.genre) == 0) {
			sum += game.price * game.amount;

		}
	}
	cout << "your count price($): " << sum << endl;


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
				games[i + 1] = tmp;
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


void sort_by_name_in_show()
{
	game_list_t list = read_game_list();

	cout << endl;
	cout << "Sorted by game name: " << endl;
	bubble_sort_name(list.games, list.size);
	cout << endl;

	for (int i = 0; i < list.size; i++) {
		print_game_info(list.games[i]);
	}

	delete list.games;
}

void sort_by_price_in_show()
{
	game_list_t list = read_game_list();

	cout << endl;
	cout << "Sorted by game price: " << endl;
	bubble_sort_price(list.games, list.size);
	cout << endl;

	for (int i = 0; i < list.size; i++) {
		print_game_info(list.games[i]);
	}

	delete list.games;
}

void show_publishers()
{
	publisher_list_t list = read_publisher_list();

	for (int i = 0; i < list.size; i++) {
		print_publisher_info(list.publishers[i]);
	}

	delete list.publishers;
}

void show_games()
{
	game_list_t list = read_game_list();

	int choice = -1;
	bool done = false;
	while (!done)
	{
		system("cls");
		cout << "\n---------MENU----------\n";
		cout << "1. Sort by game name\n2. Sort by game price\n3. show unsorted\n";
		cout << "Enter your choice>";
		cin >> choice;

		switch (choice)
		{
		case 1: 
			sort_by_name_in_show();
			done = true;
		case 2: 
			sort_by_price_in_show();
			done = true;
		case 3: 
			for (int i = 0; i < list.size; i++) {
				print_game_info(list.games[i]);
			}
			done = true;
		}
	}

	delete list.games;
}



void search_menu()
{
	int choice = -1;
	char name[64];
	int id;

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
			cout << "Enter publisher id: \n";
			cin >> id;

			search_by_publisher(id);
			return;

		case 3:
			float max_price;
			cout << "Enter max price\n";
			cin >> max_price;

			filter_by_price(max_price);
			return;


		case 4:
			cout << "Enter publisher id: \n";
			cin >> id;

			count_copies_by_publisher(id);
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