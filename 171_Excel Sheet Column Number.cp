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
 
 
 Given a column title as appear in an Excel sheet, return its corresponding column number.
 
 For example:
 
 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28

 

 
*/



class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        if(s.empty()) return res;
        int n = s.size();
        int i = 0;
        while(i<n){
            res = res*26 + s[i]-'A'+1;
            i++;
        }
        return res;
    }
};






