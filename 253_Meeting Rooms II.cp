//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]],
 return 2.
 
 
*/

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval(int s, int e):start(s),end(e) {}
};

class Solution{
private:
    static bool comp(const Interval& interval1, const Interval& interval2){
        return interval1.start<interval2.start;
    }
    
    
    
public:
    int getRoomNumber(vector<Interval>& rooms, Interval interval){
        for(int i = 0; i<rooms.size(); i++){
            if(rooms[i].end<=interval.start)
                return i;
        }
        return -1;
    }
    
    int minMeetingRoom(vector<Interval>& intervals){
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> rooms;
        for(int i = 0; i<intervals.size(); i++){
            int idx = getRoomNumber(rooms, intervals[i]);
            if(idx==-1)
                rooms.push_back(intervals[i]);
            else rooms[idx] = intervals[i];
        }
        return (int)rooms.size();
    }
};





















