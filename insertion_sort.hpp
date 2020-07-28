#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <typename Comparable>
void InsertionSort(long long left, long long right, vector<Comparable>* list) {
	for (long long i = left; i <= right; i++) {
		Comparable temp = (*list)[i];
		if(i == 0)
			continue;

		// Find the spot to insert.
		long long j = 0;
		while((*list)[i] > (*list)[j] && j <= i){
			j++;
		}

		// Push values out of the way.
		long long push_back = i;
		while(push_back > j){
			(*list)[push_back] = (*list)[push_back - 1];
			push_back--;
		}

		(*list)[j] = temp;
	}
}

template <typename Comparable>
void InsertionSort(vector<Comparable>* list){
	InsertionSort(0, list->size() - 1, list);
}