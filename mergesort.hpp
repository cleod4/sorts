#pragma once
#include <vector>
#include <iostream>

using namespace std;

template <typename Comparable>
void merge(vector<Comparable> &list, vector<Comparable> &space, const long long start, const long long mid, const long long end){
	// cout << "merging: " << start << "," << mid << "," << end << endl;
	long long len = start;
	long long left = start;
	long long right = mid+1;

	for(; len <= end; len++){
		if(left <= mid && right <= end){
			// see which one is smaller
			if(list[left] < list[right]){
				space[len] = list[left];
				left++;
			} else {
				space[len] = list[right];
				right++;
			}
		} else if(left <= mid){
			space[len] = list[left];
			left++;
		} else {
			space[len] = list[right];
			right++;
		}
	}

	// copy temp back
	for(long long i = start; i <= end; i++){
		list[i] = space[i];
	}
}

template <typename Comparable>
void mergesort(vector<Comparable> &list, vector<Comparable> &space, long long start, long long end){
	// cout << start << " " << end << endl;
	if(end - start == 0) // size 1
		return;

	// if not mergesort left
	long long mid = (start+end)/2;
	mergesort(list, space, start, mid);
	// mergesort right
	mergesort(list, space, mid+1, end);
	// merge both
	merge(list, space, start, mid, end);
}

template <typename Comparable>
void mergesort(vector<Comparable> &list){
	vector<Comparable> space;
	space.resize(list.size());

	mergesort(list, space, 0, list.size()-1);
}