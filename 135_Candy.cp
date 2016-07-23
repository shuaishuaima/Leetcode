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
 
 There are N children standing in a line. Each child is assigned a rating value.
 
 You are giving candies to these children subjected to the following requirements:
 
 Each child must have at least one candy.
 Children with a higher rating get more candies than their neighbors.
 What is the minimum candies you must give?
 


 
 
 
 */



class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int n = ratings.size();
        vector<int> count(n, 1);
        int total = 0;
        for(int i = 1; i<n; i++){
            if(ratings[i]>ratings[i-1])
                count[i] = count[i-1]+1;
        }
        total += count[n-1];
        for(int i = n-2; i>=0; i--){
            if(ratings[i]>ratings[i+1])
                count[i] = max(count[i], count[i+1]+1);
            total += count[i];
        }
        return total;
    }
};







