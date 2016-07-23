//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
 
 Example:
 Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        vector<int> count(n+1, 0);
        count[1] = 10;
        int base = 9;
        for(int i = 2; i<=n; i++){
            base *= 9-i+2;
            count[i] = base;
        }
        int sum = 0;
        for(int num: count)
            sum += num;
        return sum;
    }
};








