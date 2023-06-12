#include <iostream>
#include "Newspaper.h"
using namespace std;

struct node
{
	Newspaper key_value{}; //���� � �������� ����, ���� int
	node* left;    //��������� �� ������ �������
	node* right;   //��������� �� ������� �������

	node() : left(nullptr), right(nullptr) {}
};

class btree
{
public:
	btree(); //�����������
	~btree(); //����������

	void insert(Newspaper key); //������� �������
	node* search(Newspaper key); //������� ������
	void destroy_tree(); //������� �������� ������

private:
	void destroy_tree(node* leaf);		//����������� ������� �������� ������
	void insert(Newspaper key, node* leaf);	//����������� ������� //���������� ���� � ������
	node* search(Newspaper key, node* leaf);	//����������� ������� ������ ���� ������ � �������� �������� ���������

	node* root;	//������� ������(�������� ����)

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