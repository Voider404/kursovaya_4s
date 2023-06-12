#include <iostream>
using namespace std;

struct Newspaper {
	string name{}; 	// �������� ������
	int index{}; 	// ������ �������
	string editor{}; 	// ��� ���������
	int price{}; 	// ���� ���������� ������

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