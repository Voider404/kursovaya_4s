#pragma once

#include <iostream>
#include <string>

struct Newspaper {
	std::string name{}; 	// Название газеты
	int index{}; 	// Индекс издания
	std::string editor{}; 	// ФИО редактора
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

inline std::ostream& operator<<(std::ostream& out, Newspaper& np)
{
	return out
		<< "Newspaper name:   " << np.name << '\n'
		<< "Newspaper index:  " << np.index << '\n'
		<< "Newspaper editor: " << np.editor << '\n'
		<< "Newspaper price:  " << np.price << '\n';
}

inline std::istream& operator>>(std::istream& in, Newspaper& np)
{
	std::getline(in >> std::ws, np.name);
	in >> np.index;
	std::getline(in >> std::ws, np.editor);
	return in >> np.price;
}

struct RBS_Tree
{
    Newspaper key;
    int size;
    RBS_Tree* left;
    RBS_Tree* right;
    RBS_Tree(Newspaper k) : key(k), left(0), right(0), size(1) {}
};

namespace RBST
{
    RBS_Tree* find(RBS_Tree*, Newspaper&);

    RBS_Tree* insert(RBS_Tree*, Newspaper&);

    int getsize(RBS_Tree*);

    RBS_Tree* insertroot(RBS_Tree*, Newspaper&);

    RBS_Tree* join(RBS_Tree*, RBS_Tree*);

    RBS_Tree* remove(RBS_Tree*, Newspaper&);
}