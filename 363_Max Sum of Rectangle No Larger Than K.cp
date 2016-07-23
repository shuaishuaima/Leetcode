//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
 
 Example:
 Given matrix = [
 [1,  0, 1],
 [0, -2, 3]
 ]
 k = 2
 The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
 
 Note:
 The rectangle inside the matrix must have an area > 0.
 What if the number of rows is much larger than the number of columns?
 
 */

/*Maximum Sum Rectangular Submatrix in Matrix dynamic programming/2D kadane*/

#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        int res = INT_MIN;
        for(int left = 0; left<col; left++){
            vector<int> sums(row, 0);
            for(int right = left; right<col; right++){
                for(int i = 0; i<row; i++)
                    sums[i] += matrix[i][right];
                
                
                set<int> cache;
                cache.insert(0);
                int sum = 0, temp = INT_MIN;
                for(auto s: sums){
                    sum += s;
                    auto it = cache.lower_bound(sum-k);
                    if(it!=cache.end()) temp = max(temp, sum - *it);
                    cache.insert(sum);
                }
                res = max(res, temp);
            }
            
        }
        return res;
    }
};




/*
 
    Given an array of integers A and an integer k, find a subarray that contains the largest sum, subject to a constraint that the sum is less than k?
 
*/

int best_cumulative_sum(int ar[],int N,int K)
{
    set<int> cumset;
    cumset.insert(0);
    int best=0,cum=0;
    for(int i=0;i<N;i++)
    {
        cum+=ar[i];
        set<int>::iterator sit=cumset.upper_bound(cum-K);
        if(sit!=cumset.end()) best=max(best,cum-*sit);
        cumset.insert(cum);
    }
    return best;
}


