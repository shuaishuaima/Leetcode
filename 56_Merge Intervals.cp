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
    
 Given a collection of intervals, merge all overlapping intervals.
 
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].
 

 
 
 */



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    bool static comp(const Interval& v1, const Interval& v2){
        return v1.start<v2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(), intervals.end(), comp);
        Interval pre = intervals[0];
        for(int i = 1; i<intervals.size(); i++){
            Interval cur = intervals[i];
            if(pre.end<cur.start){
                res.push_back(pre);
                pre = cur;
            }
            else{
                pre.end = max(pre.end, cur.end);
            }
        }
        res.push_back(pre);
        return res;
    }
};