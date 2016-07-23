//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

/*
 
 Problem Description:
 
 Given a string, determine if a permutation of the string could form a palindrome.
 
 For example,
 "code" -> False, "aab" -> True, "carerac" -> True.
 
 Hint:
 
 Consider the palindromes of odd vs even length. What difference do you notice?
 Count the frequency of each character.
 If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
 
*/

class Solution{
public:
    bool canPermutePalindrome(string s){
        int odd= 0;
        vector<int> count(256, 0);
        for(auto c: s)
            odd += ++count[c]&1?1:-1;
        return odd<=1;
    }
    

};

int main(int argc, const char * argv[]) {
    

    return 0;
}



























