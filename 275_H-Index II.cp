//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>


using namespace std;

/*
 
 Problem Description:
 
 Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 
 Hint:
 
 Expected runtime complexity is in O(log n) and the input is sorted.
 
*/





class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(citations[mid]>n-mid)
                high = mid-1;
            else if(citations[mid]<n-mid)
                low = mid+1;
            else return n-mid;
        }
        return n-low;
    }
};











