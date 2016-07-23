//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Let us assume that we have a special keyboard with only the following four keys:
 Key 1:  Prints 'A' on screen
 Key 2: (Ctrl-A): Selects screen
 Key 3: (Ctrl-C): Copy selection to buffer
 Key 4: (Ctrl-V): Prints buffer on screen appending it after what has already been printed.
 If you can only press this keyboard for N times, write a program which computes maximum numbers of As possible. That is input for the program is N and output of the program is number indicating maximum As possible.
 
 */

#include <iostream>
#include <vector>
#include <utility>


/*
 
 If number of allowed keystrokes(N) is less than 7, then the maximum number of As possible is N itself. You should be able to verify this yourself.
 
 It turns out that for N greater than or equal to 7, to produce maximum number of As, the sequence of N keystrokes that will be used will always end with a suffix of Ctrl-A, Ctrl-C, followed by all Ctrl-V's. The main task then is to find out the critical-point after which we should put above suffix of keystrokes to get maximum number of As.
 
 
 
 
*/

class Solution {
public:
    int FindMaxAs(int n){
        vector<int> count(n, -1);
        int maxi = 0;
        helper(n, count, maxi);
        return maxi;
    }
    void helper(int n, vector<int>& count, int maxi){
        if(n<7) return n;
        int multiplier = 2;
        for(int i = n-3; i>=0; i--){
            if(count[i]==-1)
                count[i] = helper(i, count, maxi);
            int temp = count[i]*multiplier;
            if(temp>maxi)
                maxi = temp;
            multiplier++;
        }
    }
};

























