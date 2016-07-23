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
    
 Given an absolute path for a file (Unix-style), simplify it.
 
 For example,
 path = "/home/", => "/home"
 path = "/a/./b/../../c/", => "/c"
 click to show corner cases.
 
 Corner Cases:
 Did you consider the case where path = "/../"?
 In this case, you should return "/".
 Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 In this case, you should ignore redundant slashes and return "/home/foo".

 */



class Solution {
public:
    string simplifyPath(string path) {
        istringstream is(path);
        string vs;
        vector<string> strs;
        while(getline(is,vs,'/')){
            if(vs=="." || vs.empty()) continue;
            else if(vs==".."){
                if(!strs.empty())
                    strs.pop_back();
            }
            else strs.push_back(vs);
        }
        string res;
        if(strs.empty()) return "/";
        else {
            for(auto str: strs)
                res += '/'+str;
        }
        return res;
    }
};






