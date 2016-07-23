//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Assume you have an array of length n initialized with all 0's and are given k update operations.
 Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
 Return the modified array after all k operations were executed.
 Example:
 Given:
 
 length = 5,
 updates = [
 [1,  3,  2],
 [2,  4,  3],
 [0,  2, -2]
 ]
 
 Output:
 
 [-2, 0, 3, 5, 3]
 Explanation:
 Initial state:
 [ 0, 0, 0, 0, 0 ]
 
 After applying operation [1, 3, 2]:
 [ 0, 2, 2, 2, 0 ]
 
 After applying operation [2, 4, 3]:
 [ 0, 2, 5, 5, 3 ]
 
 After applying operation [0, 2, -2]:
 [-2, 0, 3, 5, 3 ]
 
 Hint:
 Thinking of using advanced data structures? You are thinking it too complicated.
 For each update operation, do you really need to update all elements between i and j?
 Update only the first and end element is sufficient.
 The optimal time complexity is O(k + n) and uses O(1) extra space.
 
 */

#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    vector<int> getModifiedArray(int n, vector<vector<int>> & update){
        vector<int> res(n);
        for(auto u: update){
            int value = u[2];
            int start = u[0];
            int end = u[1];
            
            res[start] += value;
            if(end+1<n) res[end+1] -= value;
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += res[i];
            res[i] = sum;
        }
        return res;
    }
};







