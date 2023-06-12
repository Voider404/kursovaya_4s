#include <iostream>
#include "Newspaper.h"
using namespace std;

struct node
{
	Newspaper key_value{}; //ключ – значение узла, типа int
	node* left;    //указатель на левого потомка
	node* right;   //указатель на правого потомка

	node() : left(nullptr), right(nullptr) {}
};

class btree
{
public:
	btree(); //Конструктор
	~btree(); //Деструктор

	void insert(Newspaper key); //Функция вставки
	node* search(Newspaper key); //Функция поиска
	void destroy_tree(); //Функция удаления дерева

private:
	void destroy_tree(node* leaf);		//Рекурсивная функция удаления дерева
	void insert(Newspaper key, node* leaf);	//Рекурсивная функция //добавления узла в дерево
	node* search(Newspaper key, node* leaf);	//Рекурсивная функция поиска узла дерева с заданным ключевым значением

	node* root;	//Атрибут класса(Корневой узел)

};



ostream& operator<<(ostream& out, Newspaper& np)
{
	return out
		<< "Newspaper name:   " << np.name << '\n'
		<< "Newspaper index:  " << np.index << '\n'
		<< "Newspaper editor: " << np.editor << '\n'
		<< "Newspaper price:  " << np.price << '\n';
}

istream& operator>>(istream& in, Newspaper& np)
{
	getline(in >> ws, np.name);
	in >> np.index;
	getline(in >> ws, np.editor);
	return in >> np.price;
}