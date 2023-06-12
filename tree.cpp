#include <iostream>
#include "tree.h"
void btree::destroy_tree()
{
	destroy_tree(root);
}

btree::btree()
{
	root = NULL;  // Корневой узел без дочерних элементов
}

btree::~btree()
{
	destroy_tree(); //При удалении дерева, необходимо удалить все элементы
}

void btree::destroy_tree(node* leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(Newspaper key, node* leaf)	//(Новое ключевое значение, указатель на текущий узел)	
{
	if (key < leaf->key_value)  	//Если новое ключевое значение меньше чем ключевое значение в узле
	{
		if (leaf->left != NULL)		//И если левый указатель узла инициализирован
			insert(key, leaf->left);		//Функция вызывает саму себя, для левого узла потомка
		else		//Иначе (если левый потомок не инициализирован)
		{
			leaf->left = new node;		//Функция создаст и поместит новый элемент на место левого потомка.
			leaf->left->key_value = key;	//Внесёт новое ключевое значение в элемент.
			leaf->left->left = NULL;    	//Установит левый дочерний указатель 
			leaf->left->right = NULL;   	//и правый дочерний указатель в NULL.
		}
	}
	else if (key >= leaf->key_value)		//Иначе Если новое ключевое значение не //меньше ключевого значения в узле 
	{
		if (leaf->right != NULL)		//И если правый указатель инициализирован,
			insert(key, leaf->right);		//То функция вызывает саму себя, для правого //потомка
		else		//Иначе(если правый потомок не //инициализирован)
		{
			leaf->right = new node;		//Функция создаст и поместит новый элемент на //место правого потомка.
			leaf->right->key_value = key;	//Внесёт новое ключевое значение в элемент.
			leaf->right->left = NULL;  	//Установит левый дочерний указатель
			leaf->right->right = NULL;      //и правый дочерний указатель в NULL.
		}
	}
}

node* btree::search(Newspaper key, node* leaf)	//(Ключевое значение, указатель на узел)
{
	if (leaf != NULL)	//Если узел инициализирован
	{
		if (key == leaf->key_value)	//И ключевое значение узла совпадает с искомым ключевым значением.
			return leaf;	//Возвращается указатель на найденный элемент.
		if (key < leaf->key_value)	//Иначе, если 
		//искомое ключевое значение меньше ключевого значения узла
			return search(key, leaf->left);	//Вызывается эта же функция для левого потомка.
		else
			return search(key, leaf->right);	//Вызывается эта же функция для правого потомка.
	}
	else return NULL;
}