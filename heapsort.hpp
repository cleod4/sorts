#pragma once
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

inline long long LeftChild(long long i){
	return 2 * i + 1;
}

template <typename Comparable>
void PercDown(long long i, long long n, vector<Comparable>* list) {
	long long child;
	Comparable temp;

	for (temp = (*list)[i]; LeftChild(i) < n; i = child) {
		child = LeftChild(i);
		if (child != n - 1 && (*list)[child] < (*list)[child + 1]) {
			child++;
		}

		if (temp < (*list)[child]) {
			(*list)[i] = (*list)[child];
		}

		else
			break;
	}

	(*list)[i] = temp;
}

template <typename Comparable>
void HeapSort(long long left, long long right, vector<Comparable>* list) {
	for (int i = (left+right) / 2; i >= 0; i--)
		PercDown(i, list->size(), list);
	
	for (int i = right; i > 0; i--) {
		swap((*list)[0], (*list)[i]);
		PercDown(left, i, list);
	}
}

template <typename Comparable>
void HeapSort(vector<Comparable>* list) {
	HeapSort(0, list->size()-1, list);
}