#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>

// Include the sorts.
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "heapsort.hpp"
#include "quicksort.hpp"
#include "shellsort.hpp"
#include "bubble_sort.hpp"

using namespace std;
using namespace std::chrono;

enum SortType {
	INSERTION_SORT,
	MERGE_SORT,
	HEAPSORT,
	QUICKSORT,
	SHELLSORT,
	BUBBLE_SORT
};

void SortWrapper(SortType sort_type, vector<long long>* container) {
	high_resolution_clock::time_point start_time = high_resolution_clock::now();
	string sort_name = "";
	switch (sort_type) {
		case(INSERTION_SORT):
			InsertionSort(container);
			sort_name = "Insertion Sort";
			break;
		case(MERGE_SORT):
			MergeSort(container);
			sort_name = "MergeSort";
			break;
		case(HEAPSORT):
			HeapSort(container);
			sort_name = "HeapSort";
			break;
		case(QUICKSORT):
			QuickSort(container);
			sort_name = "QuickSort";
			break;
		case(SHELLSORT):
			ShellSort(container);
			sort_name = "ShellSort";
			break;
		case(BUBBLE_SORT):
			BubbleSort(container);
			sort_name = "BubbleSort";
			break;
		default:
			break;
	}
	high_resolution_clock::time_point end_time = high_resolution_clock::now();

	cout << sort_name << " took: " << duration_cast<microseconds>(end_time
		- start_time).count() << " microseconds" << endl;
}

int main(void) {
	long long container_size = 10;
	vector<long long> container;
	cout << "Size of container: ";
	cin >> container_size;
	srand(time(NULL));

	container_size = abs(container_size);

	// Create container of size.
	for(long long i = 0; i < container_size; i++){
		container.push_back(rand() % container_size);
	}

	bool valid_input = false;
	unsigned int input = 1;

	// Copy the containers.
	vector<vector<long long>> containers;
	containers.resize(6);

	containers[0] = container;
	containers[1] = container;
	containers[2] = container;
	containers[3] = container;
	containers[4] = container;
	containers[5] = container;

	thread thread1(SortWrapper, INSERTION_SORT, &containers[0]);
	thread thread2(SortWrapper, MERGE_SORT, &containers[1]);
	thread thread3(SortWrapper, HEAPSORT, &containers[2]);
	thread thread4(SortWrapper, QUICKSORT, &containers[3]);
	thread thread5(SortWrapper, SHELLSORT, &containers[4]);
	thread thread6(SortWrapper, BUBBLE_SORT, &containers[5]);

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();
	thread6.join();

	for (int i = 1; i < containers.size(); i++) {
		if (containers[i] != containers[i-1]) {
			// We have a mismatch, log it.
			cout << "Mismatch on container: " << i - 1 << " and " << i << endl;
			for (int j = 0; j < containers[i].size(); j++) {
				if (containers[i-1][j] != containers[i][j]) {
					cout << "j:" << j << ":" << containers[i-1][j] << ":"
						<< containers[i][j] << endl;
				}
			}
		}
	}

	return 0;
}