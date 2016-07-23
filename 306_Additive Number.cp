//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//
/*
 
 
 Additive number is a string whose digits can form additive sequence.
 
 A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
 
 For example:
 "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 
 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 1 + 99 = 100, 99 + 100 = 199
 Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 
 Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
 
 Follow up:
 How would you handle overflow for very large input integers?
 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        if(n<=2) return false;
        for(int i = 1; i<=n/2; i++){
            for(int j = 1; j<=(n-1)/2; j++){
                if(helper(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;
            }
        }
        return false;
    }
    bool helper(string s1, string s2, string s3){
        if((s1.size()>1 && s1[0]=='0') || (s2.size()>1 && s2[0]=='0')) return false;
        string sum = add(s1, s2);
        if(s3==sum) return true;
        if(s3.size()<=sum.size() || s3.substr(0, sum.size())!=sum) return false;
        return helper(s2, sum, s3.substr(sum.size()));
    }
    string add(string s1, string s2){
        int m = s1.size(), n = s2.size();
        string res;
        int i = m-1, j = n-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            int sum = (i>=0?s1[i--]-'0':0)+(j>=0?s2[j--]-'0':0)+carry;
            res = to_string(sum%10)+res;
            carry = sum/10;
        }
        return res;
    }
};

























