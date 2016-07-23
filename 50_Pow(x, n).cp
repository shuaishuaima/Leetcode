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
    
 Implement pow(x, n).
 
 */



class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            if(n==INT_MIN){
                n = n+2;
                n = -n;
                x = 1/x;
            }
            else {
                n = -n;
                x = 1/x;
            }
        }
        return n&1?x*pow(x*x, n/2):pow(x*x, n/2);
    }
};