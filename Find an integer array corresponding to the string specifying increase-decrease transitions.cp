//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Given a string of size 'n' where each character can be either 'd' or 'i' and nothing else. If character 'd' denotes decrease in value and character 'i' denotes increase in value then how can we build an integer array of size 'n+1' created by using numbers from 1 to 'n+1' such that this array holds one to one correspondence with the input string.

 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    vector<int> IncreasDecreaseTransition(string s){
        int n = s.size();
        vector<int> res(n+1, 0);
        int iCount = 0;
        for(auto c: s){
            if(c=='i')
                iCount++;
        }
        int increaseValue = n+2-iCount;
        int startValue = increaseValue-1;
        int decreaseValue = startValue-1;
        res[0] = startValue;
        for(int i = 0; i<n; i++){
            if(s[i]=='i'){
                res[i+1] = increaseValue;
                increaseValue++;
            }
            if(s[i]=='d'){
                res[i+1] = decreaseValue;
                decreaseValue--;
            }
        }
        return res;
    }
};

























