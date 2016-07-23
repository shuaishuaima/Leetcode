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
    
 Given an integer, convert it to a roman numeral.
 
 Input is guaranteed to be within the range from 1 to 3999.
 */


class Solution {
public:
    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string result;
        int i = 0;
        while(num>0){
            int k = num/values[i];
            for(int j = 0; j<k; j++){
                result += symbols[i];
                num -= values[i];
            }
            i++;
        }
        return result;
    }
};