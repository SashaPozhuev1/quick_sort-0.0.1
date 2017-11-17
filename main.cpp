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

void quick_sort(double * mass, int size, int right_border, int left_border) {
    /* int j = right_border, next;

     while (left_border < j) {
         while (mass[left_border] < mass[j]) {
             j--;
         }

         if (mass[j] <= mass[left_border]) {
             next = mass[j];
             mass[j] = mass[left_border + 1];
             mass[left_border + 1] = next;
             next = mass[left_border + 1];
             mass[left_border + 1] = mass[left_border];
             mass[left_border] = next;

             left_border++;
         }
     }

     if (left_border - 2 > right_border - left_border) {
         next = left_border;
         left_border = 0;
         right_border = next;
         quick_sort(mass, size, right_border, left_border);
     }
     else {
         right_border = size - 1;
         quick_sort(mass, size, right_border, left_border);
     }
 */
    int i = left_border, j = right_border, next;
    while(left_border < right_border) {
        while(mass[right_border] > mass[left_border] && left_border < right_border) {
            right_border--;
        }
        if(left_border < right_border && mass[right_border] >= mass[left_border]) {
            swap(mass[left_border], mass[right_border]);
            swap(mass[left_border + 1], mass[right_border]);

            left_border++;
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
            quick_sort(mass, size, size - 1, 0);
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
