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
    
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
 
 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 
 Note:
 You are not suppose to use the library's sort function for this problem.
 
 click to show follow up.
 
 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 
 Could you come up with an one-pass algorithm using only constant space?

 */



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int one = 0, two = n-1;
        for(int i = 0; i<=two; i++){
            while(i<=two && nums[i]==2) swap(nums[i], nums[two--]);
            while(i>=one && nums[i]==0) swap(nums[i], nums[one++]);
        }
    }
};














