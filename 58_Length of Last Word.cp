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
    
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 For example,
 Given s = "Hello World",
 return 5.
 

 
 
 */



class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int count = 0;
        int tail = s.size()-1;
        while(tail>=0 && s[tail]==' ') tail--;
        while(tail>=0 && s[tail]!=' '){
            count++;
            tail--;
        }
        return count;
        
    }
};