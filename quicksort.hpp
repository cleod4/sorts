#pragma once
#include <vector>
#include <iostream>
#include <utility>

#include "insertion_sort.hpp"
#include "heapsort.hpp"

using namespace std;

template <typename Comparable>
Comparable& median3(long long left, long long right, vector<Comparable>* list) {
	long long center = (left + right)/2;

	if((*list)[left] > (*list)[center])
		swap((*list)[left], (*list)[center]);
	if((*list)[left] > (*list)[right])
		swap((*list)[right], (*list)[left]);
	if((*list)[center] > (*list)[right])
		swap((*list)[center], (*list)[right]);

	swap((*list)[center], (*list)[right]);
	return (*list)[right];
}

template <typename Comparable>
void quicksort(long long left, long long right, vector<Comparable>* list) {
	if(left >= right)
		return;

	if (right - left == 1 && (*list)[left] > (*list)[right]) { // Size 2
		swap((*list)[left], (*list)[right]);
		return;
	}

	Comparable pivot = median3(left, right, list);

	// Partition the array.
	long long i = left-1;
	long long j = right;

	for(;;) {
		while((*list)[++i] < pivot){}
		while((*list)[--j] > pivot){}

		if (i < j) {
			swap((*list)[i], (*list)[j]);
		} else {
			break;
		}
	}

	// Restore pivot.
	swap((*list)[i], (*list)[right]);

	// Quicksort left.
	quicksort(left, i - 1, list);

	// Quicksort right.
	quicksort(i + 1, right, list);
}

template <typename Comparable>
void quicksort(vector<Comparable>* list){
	quicksort(0, list->size()-1, list);
}