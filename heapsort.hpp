#pragma once
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

inline long long left_child(long long i){
	return 2 * i + 1;
}

template <typename Comparable>
void perc_down(vector<Comparable> &list, long long i, long long n){
	long long child;
	Comparable temp;

	for( temp = list[i]; left_child(i) < n; i = child){
		child = left_child(i);
		if(child != n - 1 && list[child] < list[child + 1])
			child++;
		if(temp < list[child])
			list[i] = list[child];
		else
			break;
	}
	list[i] = temp;
}

template <typename Comparable>
void heapsort(vector<Comparable> &list, long long left, long long right){
	for(int i = (left+right) / 2; i >= 0; i--)
		perc_down(list, i, list.size());
	for(int i = right; i > 0; i--){
		swap(list[0], list[i]);
		perc_down(list, left, i);
	}
}

template <typename Comparable>
void heapsort(vector<Comparable> &list){
	heapsort(list, 0, list.size()-1);
}