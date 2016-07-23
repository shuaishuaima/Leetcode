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
 Discription:
    
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character

 */



class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n+1, 0);
        for(int i = 0; i<=n; i++)
            dp[i] = i;
        for(int i = 1; i<=m; i++){
            int pre = dp[0];
            dp[0] = i;
            for(int j = 1; j<=n; j++){
                int temp = dp[j];
                if(word1[i-1]==word2[j-1])
                    dp[j] = pre;
                else dp[j] = min(pre, min(dp[j-1], dp[j]))+1;
                pre = temp;
            }
        }
        return dp[n];
    }
};


/*
 int m = word1.size(), n = word2.size();
 vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
 for(int i = 0; i<=m; i++)
 dp[i][0] = i;
 for(int j = 0; j<=n; j++)
 dp[0][j] = j;
 for(int i = 1; i<=m; i++){
 for(int j = 1; j<=n; j++){
 if(word1[i-1]==word2[j-1])
 dp[i][j] = dp[i-1][j-1];
 else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
 }
 }
 return dp[m][n];
 
 
 
 
 
 
