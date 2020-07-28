#pragma once
#include <vector>
#include <iostream>
#include <utility> // swap

using namespace std;

template <typename Comparable>
void BubbleSort(long long left, long long right, vector<Comparable>* list) {
	long long pass = 0;
	bool swapped = false;
	for (long long i = left; i <= right; i++) {
		swapped = false;
		for (long long j = left+1; j <= (right - pass); j++) {
			if ((*list)[j]<(*list)[j-1]) {
				swap((*list)[j], (*list)[j-1]);
				swapped = true;
			}
		}
		pass++;
		if (swapped == false)
			return;
	}
}

template <typename Comparable>
void BubbleSort(vector<Comparable>* list) {
	BubbleSort(0, list->size()-1, list);
}