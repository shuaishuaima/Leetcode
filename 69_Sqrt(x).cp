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
    
 Implement int sqrt(int x).
 
 Compute and return the square root of x.

 */



class Solution {
public:
    int mySqrt(int x) {
        if(x<=1) return x;
        int low = 1, high = x;
        while(low<high){
            int mid = low+(high-low)/2;
            if(x/mid>=mid) low = mid+1;
            else high = mid;
        }
        return high-1;
    }
};







