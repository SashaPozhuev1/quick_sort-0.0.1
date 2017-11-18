#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>

using namespace std;

bool read( int &size ) {
	string stroka;
	getline( cin, stroka );
	istringstream stream( stroka );

	bool success = true;

	if ( stream >> size && size > 0 ) {

	}
	else {
		success = false;
	}

	return success;
}

bool create( double * & mass, int resultsize ) {
	bool success = true;

	string stroka;
	getline( cin, stroka );
	istringstream stream( stroka );

	int size = 0;
	double element;

	mass = new double[ resultsize ];
	int i = 0;
	while ( stream >> element ) {
		if ( size < resultsize ) {
			mass[i] = element;
			i++;
			size++;
		}
		else {
			success = false;
			break;
		}
	}

	if ( resultsize > size ) {
		success = false;
	}

	return success;
}

void write( double * mass, int size ) {
	for ( int i = 0; i < size; i++ ) {
		cout << mass[ i ];
		if ( i != size - 1 ) {
			cout << ' ';
		}
		else {
			cout << '\n';
		}
	}
}

void quick_sort( double * mass, int size, int right, int left ) {	
	int i = left, j = right;

	while ( left < right ) {
		while ( mass[ left ] < mass[ right ] && left < right ) {
			right--;
		}
		if ( mass[ left ] >= mass[ right ] && left < right ) {
			swap( mass[ left ], mass[ right ] );
			swap( mass[ left + 1 ], mass[ right ] );
			left++;
		}
	}

	if ( j != left + 1 && left + 1 < size - 1 && j > left + 1 ) {
		quick_sort( mass, size, j, left + 1 );
	}
	if ( left - 1 != i && left - 1 > 0 && i < left - 1 ) {
		quick_sort( mass, size, left - 1, i );
	}
}

void error() {
	cout << "An error has occured while reading input data.\n";
}

int main()
{
	int size = 0;
	double * mass = nullptr;

	if ( read( size ) ) {
		if ( create( mass, size ) ) {
			quick_sort( mass, size, size - 1, 0 );
			write( mass, size );
			delete[] mass;
		}
		else {
			error();
		}
	}
	else {
		error();
	}

	system( "pause" );
	return 0;
}
