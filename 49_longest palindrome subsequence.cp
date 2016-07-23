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
    int LongestPalindromeSubsequence(string s){
        int n = s.size();
        if(n==0) return 0;
        vector<vector<int>> count(n, vector<int>(n,0));
        for(int i = 0; i<n; i++)
            count[i][i] = 1;
        for(int len = 2; len<=n; len++){
            for(int i = 0; i<n-len+1; i++){
                int j = i+len-1;
                if(len == 2 && s[i]==s[j])
                    count[i][j] = 2;
                else if(s[i]== s[j])
                    count[i][j] = count[i+1][j-1]+2;
                else count[i][j] = max(count[i+1][j], count[i][j-1]);
            }
        }
        return count[0][n-1];
    }
};

























