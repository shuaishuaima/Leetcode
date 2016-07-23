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

bool oneEdit(string s, string t);

/*
 
 
 Question:
 Given two strings S and T, determine if they are both one edit distance apart. Hint:
 1. If | n – m | is greater than 1, we know immediately both are not one-edit distance apart.
 2. It might help if you consider these cases separately, m == n and m ≠ n.
 3. Assume that m is always ≤ n, which greatly simplifies the conditional statements.
 If m > n, we could just simply swap S and T.
 4. If m == n, it becomes finding if there is exactly one modified operation. If m ≠ n, you do not have to consider the delete operation. Just consider the insert operation in T.
 
 
 
 
 
*/



bool oneEdit(string s, string t){
    int m = s.size(), n = t.size();
    if(m>n) return oneEdit(t,s);
    int shift = n-m;
    if(shift>1) return false;
    int i = 0;
    while(i<m && s[i]==t[i]) i++;
    if(i==m) return shift==1;
    if(shift == 0) i++;
    while(i<m && s[i] == t[i+shift]) i++;
    return i==m;
}








