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



class Solution {
public:
    int LongestPalindromeSubsequence(string s1, string s2){
        int m = s1.size(), n = s2.size();
        vector<vector<int>> count(m+1, vector<int>(n+1, 0));
        int maxlen = 0;
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1]==s2[j-1])
                    count[i][j] = count[i-1][j-1]+1;
                else count[i][j] = max(count[i-1][j], count[i][j-1]);
                if(count[i][j]>maxlen)
                    maxlen = count[i][j];
            }
        }
        return maxlen;
    }
};

























