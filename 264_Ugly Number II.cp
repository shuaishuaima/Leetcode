//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Write a program to find the n-th ugly number.
 
 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 
 Note that 1 is typically treated as an ugly number.
 
 Hint:
 
 The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
 An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
 The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
 Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
 
 
 
*/

#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, INT_MAX);
        res[0] = 1;
        int c2 = 0, c3 = 0, c5 = 0;
        for(int i = 1; i<n; i++){
            res[i] = min(res[c2]*2, min(res[c3]*3, res[c5]*5));
            if(res[i]==res[c2]*2) c2++;
            if(res[i]==res[c3]*3) c3++;
            if(res[i]==res[c5]*5) c5++;
        }
        return res[n-1];
    }
};














