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
	int j = right_border, next;
	
	while (left_border < j) {
		while (mass[left_border] < mass[j]) {
			j--;
		}
		
		if (mass[j] <= mass[left_border]) {
			next = mass[left_border + 1];
			mass[left_border + 1] = mass[left_border];
			mass[left_border] = mass[j];
			mass[j] = next;
			left_border++;
		}
	}
	/*
	if (left_border - 1 > size - 1 - left_border) {
		left_border = 0;
		right_border = left_border;
		quick_sort(mass, size, right_border, left_border);
	}
	else {
		right_border = size - 1;
		quick_sort(mass, size, right_border, left_border);
	}
	*/
	


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
