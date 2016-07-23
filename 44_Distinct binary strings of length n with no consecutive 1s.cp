//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array of integers(positive or negative), print the next greater element of all elements in the array. If there is no greater element then print null.
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    int Count(int n){
        if(n<=0) return 0;
        int c0 = 1, c1 = 1;
        for(int i = 2; i<=n; i++){
            int temp = c1;
            c1 = c1+c0;
            c0 = temp;
        }
        return c0+c1;
    }
    
};

























