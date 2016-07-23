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
    
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 
 */


class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(n<=numRows || numRows==1) return s;
        string res;
        for(int i = 0; i<numRows; i++){
            int pos = i;
            res += s[pos];
            int pos1 = 2*(numRows-i-1);
            int pos2 = 2*i;
            while(1){
                pos += pos1;
                if(pos>=n) break;
                if(pos1!=0) res += s[pos];
                
                pos += pos2;
                if(pos>=n) break;
                if(pos2!=0) res += s[pos];
            }
        }
        return res;
    }
};