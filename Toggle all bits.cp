//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Given a number N, toggle all the bits to the right of the most significant bit (MSB) bit (and including MSB also) in the binary representation of the number.
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    int toggleBits(int num){
        int res = 0;
        int setBit = 1;
        while(num){
            if((num&1)==0)
                res |= setBit;
            setBit <<= 1;
            num >>= 1;
        }
        return res;
    }
};

























