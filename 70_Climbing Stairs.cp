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
    
 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 */



class Solution {
public:
    int climbStairs(int n) {
        int pre = 1, cur = 1;
        for(int i = 2; i<=n; i++){
            int temp = cur;
            cur = cur+pre;
            pre = temp;
        }
        return cur;
    }
};






