//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 
 Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
 */

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int strobogrammaticInRange(string low, string high){
        int cnt = 0;
        helper(low, high, "", cnt);
        helper(low, high, "1", cnt);
        helper(low, high, "0", cnt);
        helper(low, high, "8", cnt);
    }
    void helper(string& low, string& high, string s, int &cnt){
        if(!comp(s, high)) return;
        if(comp(low, s) && comp(s, high)){
            if(s.size()==1 || s.size()>1 && s[0]!='0')
                cnt++;
        }
        helper(low, high, "0"+s+"0", cnt);
        helper(low, high, "1"+s+"1", cnt);
        helper(low, high, "8"+s+"8", cnt);
        helper(low, high, "6"+s+"9", cnt);
        helper(low, high, "9"+s+"6", cnt);
    }
    bool comp(const string& a, const string& b){
        if(a.size()!=b.size())
            return a.size()<b.size();
        int n = a.size();
        for(int i = 0; i<n; i++){
            if(a[i]<b[i])
                return true;
            else if(a[i]>b[i])
                return false;
        }
        return true;
    }
};

















