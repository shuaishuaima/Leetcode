//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 
 Write a function to deThe number is represented as a string.termine if a number is strobogrammatic. 
 */

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool isStrobogrammatic(string num){
        unordered_map<char,char> map = {{'1','1'},{'0','0'},{'8','8'},{'6','9'},{'9','6'}};
        for(int i = 0, j = num.size()-1; i<=j; i++,j--){
            if(map.find(num[i])==map.end() || map[num[i]]!=num[j])
                return false;
        }
        return true;
    }
};

















