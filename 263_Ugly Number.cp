//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 Write a program to check whether a given number is an ugly number.
 
 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 
 Note that 1 is typically treated as an ugly number.
 
 
*/

#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    bool isUgly(int num) {
        if(num<1) return false;
        for(int i = 2; i<=5 ;i++){
            while(num%i==0)
                num /= i;
        }
        return num==1;
    }
};











 


