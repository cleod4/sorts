#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

// include the sorts
#include "insertion_sort.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"
#include "quicksort.hpp"
#include "shellsort.hpp"
#include "bubblesort.hpp"

using namespace std;

int main(void) {
	long long container_size = 5;
	vector<long long> container;
	cout << "size of container: ";
	cin >> container_size;
	// cout << container_size << endl;
	srand(time(NULL));

	container_size = abs(container_size);

	// create container of size
	for(long long i = 0; i < container_size; i++){
		container.push_back(rand() % container_size);
	}

	bool valid_input = false;
	unsigned int input = 1;

	while(!valid_input){
		cout << "choose sort" << endl;
		cout << "1 - Insertion sort" << endl;
		cout << "2 - Mergesort" << endl;
		cout << "3 - Heapsort" << endl;
		cout << "4 - Quicksort" << endl;
		cout << "5 - Shellsort" << endl;
		cout << "6 - Bubble sort" << endl;
		cout << "selection: ";
		cin >> input;

		if(input > 0 && input <= 6)
			valid_input = true;
	}

	// cout << "input container: ";
	// for(long long i = 0; i < container_size; i++){
	// 	cout << container[i] << " ";
	// }

	switch(input){
		case(1):
			insertion_sort(container);
			break;
		case(2):
			mergesort(container); // needs additional space
			break;
		case(3):
			heapsort(container);
			break;
		case(4):
			quicksort(container);
			break;
		case(5):
			shellsort(container);
			break;
		case(6):
			bubblesort(container);
			break;
		default:
			break;
	}

	// cout << "output container: ";
	// for(long long i = 0; i < container_size; i++){
	// 	cout << container[i] << " ";
	// }

	return 0;
}