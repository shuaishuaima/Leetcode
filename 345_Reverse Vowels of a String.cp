//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Write a function that takes a string as input and reverse only the vowels of a string.
 
 Example 1:
 Given s = "hello", return "holle".
 
 Example 2:
 Given s = "leetcode", return "leotcede".
 
*/

#include <iostream>
#include <vector>
#include <utility>



class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int front = 0, back = n-1;
        string vowels = "aeiouAEIOU";
        while(front<back){
            while(front<back && vowels.find(s[front])==string::npos) front++;
            while(front<back && vowels.find(s[back])==string::npos) back--;
            if(front<back)
                swap(s[front], s[back]);
            front++;
            back--;
        }
        return s;
    }
    
};














