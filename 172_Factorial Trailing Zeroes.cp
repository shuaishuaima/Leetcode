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
 
 
 Given an integer n, return the number of trailing zeroes in n!.
 
 Note: Your solution should be in logarithmic time complexity.

 

 
*/



class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n>0){
            count += n/5;
            n /= 5;
        }
        return count;
    }
};






