//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Write a function that takes a string as input and returns the string reversed.
 
 Example:
 Given s = "hello", return "olleh".
 
*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    string reverseString(string s) {
        if(s.empty()) return s;
        int front = 0, back = s.size()-1;
        while(front<back){
            swap(s[front++], s[back--]);
        }
        return s;
    }
};














