//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;

class Solution{
public:
    int longestK(string s, int k){
        int n = s.size(), i = 0, begin = 0, len = INT_MIN, dist = 0;
        vector<int> count(256, 0);
        while(i<n){
            if(count[s[i]]==0) dist++;
            count[s[i]]++;
            i++;
            while(dist>k){
                count[s[begin]]--;
                if(count[s[begin]]==0) dist--;
                begin++;
            }
            len = max(len, i-begin);
        }
    }
    return len;
};

i




