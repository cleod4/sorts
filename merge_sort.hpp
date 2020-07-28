#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <typename Comparable>
void Merge(const long long start, const long long mid, const long long end,
		vector<Comparable>* list, vector<Comparable>* space) {
	long long len = start;
	long long left = start;
	long long right = mid+1;

	for (; len <= end; len++) {
		if (left <= mid && right <= end) {
			// see which one is smaller
			if ((*list)[left] < (*list)[right]) {
				(*space)[len] = (*list)[left];
				left++;
			} else {
				(*space)[len] = (*list)[right];
				right++;
			}
		} else if (left <= mid) {
			(*space)[len] = (*list)[left];
			left++;
		} else {
			(*space)[len] = (*list)[right];
			right++;
		}
	}

	// copy temp back
	for (long long i = start; i <= end; i++) {
		(*list)[i] = (*space)[i];
	}
}

template <typename Comparable>
void MergeSort(long long start, long long end, vector<Comparable>* list,
		vector<Comparable>* space) {
	if (end - start == 0) // size 1
		return;

	// Mergesort left.
	long long mid = (start+end)/2;
	MergeSort(start, mid, list, space);
	// Mergesort right
	MergeSort(mid+1, end, list, space);
	// Merge both
	Merge(start, mid, end, list, space);
}

template <typename Comparable>
void MergeSort(vector<Comparable>* list) {
	vector<Comparable> space;
	space.resize(list->size());

	MergeSort(0, list->size()-1, list, &space);
}