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
    
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...
 
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 
 Note: The sequence of integers will be represented as a string.
 
 */



class Solution {
public:
    string countAndSay(int n) {
        if(n==0) return "";
        if(n==1) return "1";
        string res = "1";
        for(int i = 1; i<n; i++){
            string temp;
            for(int j = 0; j<res.size(); j++){
                int count = 1, k = j;
                while(j+1<res.size() && res[j]==res[j+1]){
                    count++;
                    j++;
                }
                temp += to_string(count)+res[k];
            }
            res = temp;
        }
        return res;
    }
};