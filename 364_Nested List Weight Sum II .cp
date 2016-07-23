//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a nested list of integers, return the sum of all integers in the list weighted by their depth.
 
 Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 
 Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.
 
 Example 1:
 Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)
 
 Example 2:
 Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17)
 
 */

#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    int depthSumInverse(vector<NestedInteger> &nestedList){
        int weighted = 0, unweighted = 0;
        while(!nestedList.empty()){
            vector<nestedList> temp;
            for(int i = 0; i<nestedList.size(); i++){
                if(nestedList[i].isInteger())
                    unweighted += nestedList[i].getInteger();
                else{
                    temp.push_back(nestedList[i].getList());
                }
            }
            weighted += unweighted;
            nestedList = temp;
        }
        return weighted;
    }
};







