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
 Discription:
    
 There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 
 */



class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m+n;
        if(total&1)
            return helper(&nums1[0], m, &nums2[0], n, total/2+1);
        else return (helper(&nums1[0], m, &nums2[0], n, total/2+1)+ helper(&nums1[0], m, &nums2[0], n, total/2))/2.0;
    }
    
    int helper(int a[], int m, int b[], int n, int k){
        if(m>n) return helper(b, n, a, m, k);
        if(m==0) return b[k-1];
        if(k==1) return min(a[0], b[0]);
        
        int x = min(m, k/2), y = k-x;
        if(a[x-1]<b[y-1])
            return helper(a+x, m-x, b, n, k-x);
        else if(a[x-1]>b[y-1])
            return helper(a,m, b+y, n-y, k-y);
        else return a[x-1];
    }
};
