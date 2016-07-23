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
    
 The set [1,2,3,…,n] contains a total of n! unique permutations.
 
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.
 
 Note: Given n will be between 1 and 9 inclusive.
 

 */



class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n);
        fac[0] = 1;
        for(int i = 1; i<n; i++)
            fac[i] = i*fac[i-1];
        vector<char> chars;
        for(int i = 0; i<n; i++){
            char ch = '1'+i;
            chars.push_back(ch);
        }
        string res;
        for(int i = 1; i<=n; i++){
            int temp = (k-1)/fac[n-i];
            res += chars[temp];
            chars.erase(chars.begin()+temp);
            k = k-temp*fac[n-i];
        }
        return res;
    }
};