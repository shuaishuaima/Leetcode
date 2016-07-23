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
 
 There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 
 You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 
 Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 
 Note:
 The solution is guaranteed to be unique.


 
 
 
 */



class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, n = gas.size(), tank = 0, total = 0;
        for(int i = 0; i<n; i++){
            tank += gas[i]-cost[i];
            total += tank;
            if(tank<0){
                tank = 0;
                start = i+1;
            }
        }
        return total>=0?start:-1;
    }
};







