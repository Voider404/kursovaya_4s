#include <fstream>
#include <vector>
#include <clocale>
#include <chrono>

#include "RBST.h"

void bubblesort(std::vector<Newspaper>& arr) {
	size_t n = arr.size();
	for (size_t i = 0; i < n - 1; ++i) {
		for (size_t j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void selectionsort(std::vector<Newspaper>& arr) {
	size_t n = arr.size();
	for (size_t i = 0; i < n - 1; ++i) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}
}

void insertsort(std::vector<Newspaper>& np)
{
	for (size_t i = 1; i < np.size(); i++)
		for (size_t j = i; j > 0 && np[j - 1] > np[j]; j--)
			std::swap(np[j - 1], np[j]);
}

//----------------------------------------------------------------------------//
int main() {
	
    setlocale(LC_ALL, "Russian"); // на всякий
    std::vector<Newspaper> newspapers;

    // Чтение данных из текстового файла
    std::ifstream inputFile("newspapers.txt");
    if (!inputFile) {
		std::cout << "Ошибка открытия файла." << std::endl;
        return 1;
    }

	for (int i = 0; i < 5; i++) { //input to temp file
		Newspaper temp;
		inputFile >> temp;
		newspapers.push_back(temp);
	}
	
	RBS_Tree *tree = nullptr;

	for (Newspaper np : newspapers)
		tree = RBST::insert(tree, np);
	
	if (RBST::find(tree, newspapers[0]))
		std::cout << "Found!\n";
	else
		std::cout << "That sucks :(\n";
	
	//TODO: switch-case
	bubblesort(newspapers); // sort itself
	//selectionsort(newspapers);
	//insertsort(newspapers);

	for (Newspaper np : newspapers) { // console output
		std::cout << np << "\n";
	}
    return 0;
}
