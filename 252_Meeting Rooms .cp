//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]],
 return false.
 
 
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
    
    static bool isOverlap(const Interval& interval1, const Interval& interval2){
        return interval1.end > interval2.start;
    }
    
public:
    bool canAttendMeeting(vector<Interval>& intervals){
        sort(intervals.begin(), intervals.end(), comp);
        for(int i=1; i<intervals.size()-1; i++){
            if(isOverlap(intervals[i-1],intervals[i]))
                return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}



























