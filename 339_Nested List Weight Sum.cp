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
 
 Example 1:
 Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
 
 Example 2:
 Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;

int depthSum(vector<NestedInteger>& nestedList){
    return dfs(nestedList, 1);
}

int dfs(vector<NestedInteger>& nestedList, int depth){
    int n = nestedList.size();
    int res = 0;
    for(auto nest: nestedList){
        if(nest.isInteger())
            res += nest.getInteger()*depth;
        else
            res += dfs(nest.getList(), depth+1);
    }
    return res;
}





