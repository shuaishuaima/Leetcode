//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

/*
 
 
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 
 For example,
 Given [3,2,1,5,6,4] and k = 2, return 5.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ array's length.

 

 
 

 
*/

//heapsort O(n+klogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        heapsort(nums, n);
        for(int i = 0; i<k; i++){
            swap(nums[0], nums[n-1]);
            n--;
            heapify(nums, 0, n);
        }
        return nums[n];
    }
    void heapsort(vector<int>& nums, int n){
        int parent = (n-2)/2;
        for(;parent>=0; parent--){
            heapify(nums, parent, n);
        }
    }
    void heapify(vector<int>& nums, int parent, int n){
        int left = 2*parent+1, right = 2*parent+2;
        int large = parent;
        if(left<n && nums[left]>nums[large]) large = left;
        if(right<n && nums[right]>nums[large]) large = right;
        if(large!=parent){
            swap(nums[large], nums[parent]);
            heapify(nums, large, n);
        }
        
    }
};



//quicksort










