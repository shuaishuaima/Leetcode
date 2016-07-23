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
 
 
 Compare two version numbers version1 and version2.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 
 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 
 Here is an example of version numbers ordering:
 
 0.1 < 1.1 < 1.2 < 13.37
 

 
*/



class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(auto& c: version1){ if(c=='.') c=' ';}
        for(auto& c: version2){ if(c=='.') c=' ';}
        istringstream v1(version1), v2(version2);
        while(1){
            int a, b;
            if(!v1 && !v2) return 0;
            if(!(v1>>a)) a=0;
            if(!(v2>>b)) b=0;
            if(a>b) return 1;
            if(a<b) return -1;
        }
    }
};






