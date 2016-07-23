//
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
 
 Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 
 
 Example 1
 Input: "2-1-1".
 
 ((2-1)-1) = 0
 (2-(1-1)) = 2
 Output: [0, 2]
 
 
 Example 2
 Input: "2*3-4*5"
 
 (2*(3-(4*5))) = -34
 ((2*3)-(4*5)) = -14
 ((2*(3-4))*5) = -10
 (2*((3-4)*5)) = -10
 (((2*3)-4)*5) = 10
 Output: [-34, -14, -10, -10, 10]
 
*/





class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string,vector<int>> cache;
        return helper(input, cache);
    }
    vector<int> helper(string input, unordered_map<string,vector<int>>& cache){
        if(cache.find(input)!=cache.end()) return cache[input];
        vector<int> res;
        for(int i = 0; i<input.size(); i++){
            if(!isdigit(input[i])){
                string s1 = input.substr(0,i);
                string s2 = input.substr(i+1);
                vector<int> v1, v2;
                if(cache.find(s1)!=cache.end())
                    v1 = cache[s1];
                else v1 = helper(s1, cache);
                
                if(cache.find(s2)!=cache.end())
                    v2 = cache[s2];
                else v2 = helper(s2, cache);
                
                for(int a: v1){
                    for(int b: v2){
                        if(input[i]=='+') res.push_back(a+b);
                        if(input[i]=='-') res.push_back(a-b);
                        if(input[i]=='*') res.push_back(a*b);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        cache[input] = res;
        return res;
    }
    
};














