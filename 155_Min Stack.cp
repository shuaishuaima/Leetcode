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
 
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.

 
 
 
 */


class MinStack {
private:
    vector<int> min, stk;
public:
    void push(int x) {
        if(min.empty() || x<=min.back())
            min.push_back(x);
        stk.push_back(x);
    }
    
    void pop() {
        if(stk.back()==min.back())
            min.pop_back();
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return min.back();
    }
};












