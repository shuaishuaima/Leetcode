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
 
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 
 For example:
 Given "25525511135",
 
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 
 */



class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.size();
        for(int i=1; i<4 && i<n-2; i++){
            for(int j=i+1; j<i+4 && j<n-1; j++){
                for(int k=j+1; k<j+4 && k<n; k++){
                    string s1 = s.substr(0,i), s2 = s.substr(i,j-i), s3= s.substr(j,k-j), s4=s.substr(k,n-k);
                    if(valid(s1)&&valid(s2)&&valid(s3)&&valid(s4))
                        result.push_back(s1+"."+s2+"."+s3+"."+s4);
                }
            }
        }
        return result;
    }
    
    bool valid(string s){
        if(s.size()>3 || (s.size()>1 && s[0]=='0') || stoi(s)>255)
            return false;
        return true;
        
    }
};











