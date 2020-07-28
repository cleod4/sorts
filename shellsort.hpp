#pragma once
#include <vector>
#include <iostream> // this is for NULL
#include <utility> // for swap

using namespace std;

template <typename Comparable>
void ShellSort(long long left, long long right, vector<Comparable>* list){
	// Using D. Shell's gaps.
	long long gap = (right - left) / 2;

	for (; gap > 0; gap/=2) {
		for (long long i = left+gap; i <= right; i++) {
			for (long long j = i; j-gap >= 0
					&& (*list)[j] < (*list)[j-gap]; j=j-gap) {
				swap((*list)[j], (*list)[j-gap]);
			}
		}
	}
}

template <typename Comparable>
void ShellSort(vector<Comparable>* list){
	ShellSort(0, list->size()-1, list);
}