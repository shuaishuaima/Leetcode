//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    bool checkParantheses(sting s){
        int n = s.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            if(s[i]=='(')
                count++;
            else if(s[i]==')'){
                if(count==0) return false;
                else count--;
            }
        }
        return count==0;
    }
};

























