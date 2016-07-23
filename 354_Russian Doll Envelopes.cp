//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
 
 What is the maximum number of envelopes can you Russian doll? (put one inside other)
 
 Example:
 Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    static bool comp(const pair<int,int> &p1, const pair<int,int> &p2){
        if(p1.first== p2.first)
            return p1.second > p2.second;
        else return p1.first < p2.first;
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;
        int n = envelopes.size();
        dp.push_back(envelopes[0].second);
        for(int i = 1; i<n; i++){
            if(envelopes[i].second>dp.back())
                dp.push_back(envelopes[i].second);
            else{
                auto pos = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
                *pos = envelopes[i].second;
            }
        }
        return (int)dp.size();
    }
};








