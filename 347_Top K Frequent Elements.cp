//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a non-empty array of integers, return the k most frequent elements.
 
 For example,
 Given [1,1,1,2,2,3] and k = 2, return [1,2].
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 
*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> cache;
        for(int i = 0; i<nums.size(); i++){
            cache[nums[i]]++;
        }
        priority_queue<pair<int,int>> que;
        for(auto it = cache.begin(); it!=cache.end(); it++){
            que.push(make_pair(it->second, it->first));
            if(que.size()>cache.size()-k){
                res.push_back(que.top().second);
                que.pop();
            }
        }
        return res;
    }
};






//bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> cache;
        for(int num: nums)
            cache[num]++;
        vector<vector<int>> bucket(n+1);
        for(auto ca: cache)
            bucket[ca.second].push_back(ca.first);
        
        vector<int> res;
        for(int i = n; i>=0; i--){
            for(int j = 0; j<bucket[i].size(); j++){
                res.push_back(bucket[i][j]);
                if(res.size()==k)
                    return res;
            }
        }
        return res;
    }
};






