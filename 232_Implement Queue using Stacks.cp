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
 
 Implement the following operations of a queue using stacks.
 
 push(x) -- Push element x to the back of queue.
 pop() -- Removes the element from in front of queue.
 peek() -- Get the front element.
 empty() -- Return whether the queue is empty.
 Notes:
 You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


 
*/





class Queue {
private:
    stack<int> stk,temp;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!stk.empty()){
            temp.push(stk.top());
            stk.pop();
        }
        stk.push(x);
        while(!temp.empty()){
            stk.push(temp.top());
            temp.pop();
        }
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        stk.pop();
    }
    
    // Get the front element.
    int peek(void) {
        return stk.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }
};





