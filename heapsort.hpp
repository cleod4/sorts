#pragma once
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

inline long long left_child(long long i){
	return 2 * i + 1;
}

template <typename Comparable>
void perc_down(long long i, long long n, vector<Comparable>* list){
	long long child;
	Comparable temp;

	for (temp = (*list)[i]; left_child(i) < n; i = child) {
		child = left_child(i);
		if(child != n - 1 && (*list)[child] < (*list)[child + 1]) {
			child++;
		}

		if(temp < (*list)[child]) {
			(*list)[i] = (*list)[child];
		}

		else
			break;
	}

	(*list)[i] = temp;
}

template <typename Comparable>
void heapsort(long long left, long long right, vector<Comparable>* list) {
	for(int i = (left+right) / 2; i >= 0; i--)
		perc_down(i, list->size(), list);
	
	for (int i = right; i > 0; i--) {
		swap((*list)[0], (*list)[i]);
		perc_down(left, i, list);
	}
}

template <typename Comparable>
void heapsort(vector<Comparable>* list){
	heapsort(0, list->size()-1, list);
}