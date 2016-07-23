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
    
 Validate if a given string is numeric.
 
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 

 */



class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        bool isNum = false;
        while(i<n && s[i]==' ') i++;
        if(s[i]=='+' || s[i]=='-') i++;
        while(i<n && isdigit(s[i])){
            i++;
            isNum = true;
        }
        if(s[i]=='.'){
            i++;
        }
        while(i<n && isdigit(s[i])){
            i++;
            isNum = true;
        }
        if(isNum && i<n && s[i]=='e'){
            i++;
            isNum = false;
            if(s[i]=='+' || s[i]=='-') i++;
            while(i<n && isdigit(s[i])){
                i++;
                isNum = true;
            }
        }
        
        while(i<n && s[i]==' ') i++;
        return i==n && isNum;
    }
};








