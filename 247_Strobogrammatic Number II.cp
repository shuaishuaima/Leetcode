//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 
 Find all strobogrammatic numbers that are of length = n.
 */

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<string> findStrobogrammatic(int n){
        vector<string> res;
        if(n&1) res = {"0","1","8"};
        else res = {""};
        vector<string> bases = {"00","11","88","69","96"};
        int m = bases.size();
        while(n>1){
            n -= 2;
            vector<string> temp;
            for(auto re: res){
                for(int i = (n<2?1:0); i<m; i++){
                    temp.push_back(bases[i][0] + re + bases[i][1]);
                }
            }
            res = temp;
        }
        return res;
    }
};




















