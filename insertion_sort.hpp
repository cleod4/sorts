#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <typename Comparable>
void insertion_sort(vector<Comparable> &list, long long left, long long right){
	for(long long i = left; i <= right; i++){
		Comparable temp = list[i];
		if(i == 0)
			continue;

		// Find the spot to insert.
		long long j = 0;
		while(list[i] > list[j] && j <= i){
			j++;
		}

		// Push values out of the way.
		long long push_back = i;
		while(push_back > j){
			list[push_back] = list[push_back - 1];
			push_back--;
		}

		list[j] = temp;
	}
}

template <typename Comparable>
void insertion_sort(vector<Comparable> &list){
	insertion_sort(list, 0, list.size()-1);
}