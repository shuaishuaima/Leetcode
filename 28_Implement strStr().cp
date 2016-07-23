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
    
 Implement strStr().
 
 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 */




//O(mn)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(m==0 && n==0) return 0;
        else if(m==0) return -1;
        for(int i = 0; ; i++){
            for(int j = 0; ; j++){
                if(j==n) return i;
                if(i+j==m) return -1;
                if(haystack[i+j]!=needle[j]) break;
            }
        }
    }
};




//O(m+n)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        else if(haystack.empty()) return -1;
        int n = needle.size();
        vector<int> count(n, 0);
        int index = 0;
        for(int i = 1; i<n;){
            if(needle[i]==needle[index]){
                count[i] = index+1;
                index++;
                i++;
            }
            else{
                if(index>0) index = count[index-1];
                else{
                    count[i] = 0;
                    i++;
                }
            }
        }
        int i = 0, j = 0;
        while(i<haystack.size() && j<needle.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==needle.size()) return i-j;
            }
            else{
                if(j>0) j = count[j-1];
                else i++;
            }
        }
        return -1;
    }
};