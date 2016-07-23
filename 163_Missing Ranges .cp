//
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
 
 
 Question:
 Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
 For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”]
 Example Questions Candidate Might Ask:
 Q: What if the given array is empty?
 A: Then you should return [“0->99”] as those ranges are missing.
 Q: What if the given array contains all elements from the ranges? A: Return an empty list, which means no range is missing.
 
*/



vector<string> missingrange(vector<int>& nums){
    vector<string> res;
    int pre = -1, cur;
    int n = nums.size();
    for(int i = 0; i<=n; i++){
        cur = i==n?100:nums[i];
        if(cur-pre>1)
            res.push_back(making(pre+1, cur-1));
        pre = cur;

    }
    return res;
}

string making(int pre, int cur){
    return pre==cur?to_string(pre):to_string(pre)+"->"+to_string(cur);
}






