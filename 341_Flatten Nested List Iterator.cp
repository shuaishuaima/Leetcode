//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a nested list of integers, implement an iterator to flatten it.
 
 Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 
 Example 1:
 Given the list [[1,1],2,[1,1]],
 
 By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 
 Example 2:
 Given the list [1,[4,[6]]],
 
 By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 
*/

#include <iostream>
#include <vector>
#include <utility>



class NestedIterator {
private:
    vector<int> res;
    int j = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);
    }
    void helper(vector<NestedInteger> &nestedList){
        for(auto nest: nestedList){
            if(nest.isInteger())
                res.push_back(nest.getInteger());
            else helper(nest.getList());
        }
    }
    
    int next() {
        return res[j++];
    }
    
    bool hasNext() {
        return j!=res.size();
    }
};





class NestedIterator {
private:
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = n-1; i>=0; i--)
            stk.push(nestedList[i]);
    }
    
    int next() {
        NestedInteger res = stk.top();
        stk.pop();
        return res.getInteger();
    }
    
    bool hasNext() {
        while(!stk.empty()){
            if(stk.top().isInteger())
                return true;
            NestedInteger ni = stk.top();
            stk.pop();
            for(int i = ni.getList().size()-1; i>=0; i--)
                stk.push(ni.getList()[i]);
            
        }
        return false;
    }
};
