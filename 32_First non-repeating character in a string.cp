//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Find the first non repeating character in string.
 Example:
 Input : ADBCGHIEFKJLADTVDERFSWVGHQWCNOPENSMSJWIERTFB
 Output: K
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    int FirstNonRepeating(string s){
        int n = s.size();
        if(n==1) return s[0];
        vector<int> indices(256, -1);
        for(int i = 0; i<n; i++){
            if(indices[s[i]]==-1)
                indices[s[i]]=i;
            else indices[s[i]] = -2;
        }
        int res = n;
        for(int i = 0; i<256; i++){
            if(indices[i]>=0 && indices[i]<res)
                res = indices[i];
        }
        return res==n?-1:res;
    }
};

























