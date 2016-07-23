//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
 
 Example:
 Given num = 16, return true. Given num = 5, return false.
 
 Follow up: Could you solve it without loops/recursion?
 
*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && ((num&num-1)==0) && ((num&0x55555555)==num);
    }
};


class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && ((num&num-1)==0) && ((num&0x55555555)!=0);
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num>0 && ((num&num-1)==0) && ((num-1)%3==0);
    }
};