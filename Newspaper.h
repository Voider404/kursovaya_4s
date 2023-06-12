#include <iostream>
using namespace std;

struct Newspaper {
	string name{}; 	// Название газеты
	int index{}; 	// Индекс издания
	string editor{}; 	// ФИО редактора
	int price{}; 	// Цена экземпляра газеты

	bool operator>(Newspaper& np)
	{
		return name > np.name;
	}

	bool operator<(Newspaper& np)
	{
		return name < np.name;
	}

	bool operator==(Newspaper& np)
	{
		if (name == np.name && index == np.index && editor == np.editor && price == np.price)
			return true;
		return false;
	}

	bool operator>=(Newspaper& np)
	{
		return name >= np.name;
	}
};