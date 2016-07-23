45. Jump Game II//
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
    
 Given a non-negative number represented as an array of digits, plus one to the number.
 
 The digits are stored such that the most significant digit is at the head of the list.
 

 */



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int tail = n-1;
        while(tail>=0 && digits[tail]==9){
            digits[tail] = 0;
            tail--;
        }
        if(tail<0){
            digits[0] = 1;
            digits.push_back(0);
        }
        else digits[tail]++;
        return digits;
    }
};







