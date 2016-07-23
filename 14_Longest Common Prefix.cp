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
 Discription:
    
 Write a function to find the longest common prefix string amongst an array of strings.
 

 */


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        for(int i = 0; i<strs[0].size(); i++){
            for(int j = 1; j<n; j++){
                if(strs[j][i]!=strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};