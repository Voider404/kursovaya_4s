#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include <chrono>
#include <string>
#include <algorithm>
#include "tree.h"

using namespace std;


void bubblesort(vector<Newspaper>& arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void selectionsort(vector<Newspaper>& arr) {
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
	}
}

void insertsort(vector<Newspaper>& np)
{
	for (size_t i = 1; i < np.size(); i++)
		for (size_t j = i; j > 0 && np[j - 1] > np[j]; j--)
			swap(np[j - 1], np[j]);
}



//----------------------------------------------------------------------------//
int main() {
    setlocale(LC_ALL, "Russian"); // на всякий
    vector<Newspaper> newspapers;

    // Чтение данных из текстового файла
    ifstream inputFile("newspapers.txt");
    if (!inputFile) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

	for (int i = 0; i < 5; i++) { //input to temp file
		Newspaper temp;
		inputFile >> temp;
		newspapers.push_back(temp);
	}
	btree tree;

	for (Newspaper np : newspapers)
		tree.insert(np);

	if (tree.search(newspapers[0]))
		cout << "Found!\n";
	else
		cout << "That sucks :(\n";

	//TODO: switch-case
	bubblesort(newspapers); // sort itself
	//selectionsort(newspapers);
	//insertsort(newspapers);

	for (Newspaper np : newspapers) { // console output
		cout << np << "\n";
	}
    return 0;
}
