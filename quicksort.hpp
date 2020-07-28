#pragma once
#include <vector>
#include <iostream>
#include <utility>

#include "insertion_sort.hpp"
#include "heapsort.hpp"

using namespace std;

template <typename Comparable>
Comparable& median3(vector<Comparable> &list, long long left, long long right){
	long long center = (left + right)/2;
	if(list[left] > list[center])
		swap(list[left], list[center]);
	if(list[left] > list[right])
		swap(list[right], list[left]);
	if(list[center] > list[right])
		swap(list[center], list[right]);

	swap(list[center], list[right-1]);
	return list[right-1];
}

template <typename Comparable>
void quicksort(vector<Comparable> &list, long long left, long long right){
	if(left == right)
		return;

	if(right - left == 1){ // size 2
		swap(list[left], list[right]);
		return;
	}

	Comparable pivot = median3(list, left, right);

	// partition the array
	long long i = left;
	long long j = right-1;

	for(;;){
		while(list[++i] < pivot){}
		while(list[--j] > pivot){}
		if(i<j)
			swap(list[i], list[j]);
		else
			break;
	}

	// restore pivot
	swap(list[i], list[right-1]);

	// quicksort left
	quicksort(list, left, i-1);

	// quicksort right
	quicksort(list, i+1, right);
}

template <typename Comparable>
void quicksort(vector<Comparable> &list){
	quicksort(list, 0, list.size()-1);
}