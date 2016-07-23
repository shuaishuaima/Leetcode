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
 Discription:
    
 Given a roman numeral, convert it to an integer.
 
 Input is guaranteed to be within the range from 1 to 3999.
 */


class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        unordered_map<char,int> map={{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = map[s.back()];
        for(int i=s.size()-2; i>=0; i--)
            sum += map[s[i]]>=map[s[i+1]]?map[s[i]]:-map[s[i]];
        return sum;
    }
};