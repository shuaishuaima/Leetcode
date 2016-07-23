//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.
 
 Example 1:
 nums1 = [3, 4, 6, 5]
 nums2 = [9, 1, 2, 5, 8, 3]
 k = 5
 return [9, 8, 6, 5, 3]
 
 Example 2:
 nums1 = [6, 7]
 nums2 = [6, 0, 4]
 k = 5
 return [6, 7, 6, 0, 4]
 
 Example 3:
 nums1 = [3, 9]
 nums2 = [8, 9]
 k = 3
 return [9, 8, 9]
 
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k);
        for(int i = max(0, k-n); i<=m && i<=k; i++){
            vector<int> v1 = find(nums1, i);
            vector<int> v2 = find(nums2, k-i);
            vector<int> cand = merge(v1, v2, k);
            if(greater(cand, 0, res, 0))
                res = cand;
        }
        return res;
    }
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int k){
        vector<int> res(k);
        for(int i = 0, j = 0, r = 0; r<k; r++){
            res[r] = greater(nums1, i, nums2, j)?nums1[i++]:nums2[j++];
        }
        return res;
    }
    
    bool greater(vector<int>& v1, int i, vector<int>& v2, int j){
        int m = v1.size(), n = v2.size();
        while(i<m && j<n && v1[i]==v2[j]){
            i++; j++;
        }
        return j==n || (i<m && v1[i]>=v2[j]);
    }
    vector<int> find(vector<int>& nums, int k){
        vector<int> res(k);
        int n = nums.size();
        for(int i = 0, j = 0; i<n; i++){
            while(n-i>k-j && j>0 && res[j-1]<nums[i])
                j--;
            if(j<k) res[j++] = nums[i];
        }
        return res;
    }
};




























