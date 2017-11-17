#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>

using namespace std;

bool read(int &size) {
	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	bool success = true;

	if (stream >> size && size > 0) {

	}
	else {
		success = false;
	}

	return success;
}

bool create(double * & mass, int resultsize) {
	bool success = true;

	string stroka;
	getline(cin, stroka);
	istringstream stream(stroka);

	int size = 0;
	double element;

	mass = new double[resultsize];
	int i = 0;
	while (stream >> element) {
		if (size < resultsize) {
			mass[i] = element;
			i++;
			size++;
		}
		else {
			success = false;
			break;
		}
	}

	if (resultsize > size) {
		success = false;
	}

	return success;
}

void quick_sort(double * mass, int size) {
	int right_hold, left_hold, opora, schet = 0;

	////////Выбираем опорный элемент справа:
	mass[opora + 1];
	////////Выбираем опорный элемент слева:
	mass[left_hold];
	////////Сначала: 
	right_hold = size - 1;
	left_hold = 0;

	
	opora = mass[1];
	int i = 0, j = size - 1, next;
	while (i < opora && opora < j) {
		while (mass[opora] > mass[i]) {
			i++;
		}
		while (mass[opora] < mass[j]) {
			j++;
		}
		
		if (mass[i] > mass[opora]) {
			next = mass[opora - 1];
			mass[opora - 1] = mass[opora];
			mass[opora] = mass[i];
			mass[i] = next;
		}
	}
	


}

void write(double * mass, int size) {
	for (int i = 0; i < size; i++) {
		cout << mass[i];
		if (i != size - 1) {
			cout << ' ';
		}
		else {
			cout << '\n';
		}
	}
}

void error() {
	cout << "An error has occured while reading input data.\n";
}

int main()
{
	int size = 0;
	double * mass = nullptr;

	if (read(size)) {
		if (create(mass, size)) {
			
			write(mass, size);
		}
		else {
			error();
		}
	}
	else {
		error();
	}

	system("pause");
    return 0;
}
