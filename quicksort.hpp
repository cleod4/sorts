#pragma once
#include <vector>
#include <iostream>
#include <utility>

#include "insertion_sort.hpp"
#include "heapsort.hpp"

using namespace std;

template <typename Comparable>
Comparable& Median3(long long left, long long right, vector<Comparable>* list) {
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
void QuickSort(long long left, long long right, vector<Comparable>* list) {
	if(left >= right)
		return;

	if (right - left == 1 && (*list)[left] > (*list)[right]) { // Size 2
		swap((*list)[left], (*list)[right]);
		return;
	}

	Comparable pivot = Median3(left, right, list);

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

	// QuickSort left.
	QuickSort(left, i - 1, list);

	// QuickSort right.
	QuickSort(i + 1, right, list);
}

template <typename Comparable>
void QuickSort(vector<Comparable>* list){
	QuickSort(0, list->size()-1, list);
}