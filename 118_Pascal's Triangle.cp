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
 
 Given numRows, generate the first numRows of Pascal's triangle.
 
 For example, given numRows = 5,
 Return
 
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 
 

 
 */




class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==0) return res;
        vector<int> temp;
        for(int i = 0; i<numRows; i++){
            for(int j = i-1; j>=1; j--){
                temp[j] = temp[j]+temp[j-1];
            }
            temp.push_back(1);
            res.push_back(temp);
        }
        return res;
    }
};










