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
 
 
 Design and implement a TwoSum class. It should support the following operations: add and find.
 
 add(input) – Add the number input to an internal data structure.
 
 find(value) – Find if there exists any pair of numbers which sum is equal to the value.
 
 For example,
 
 add(1); add(3); add(5); find(4) true; find(7) false


 

 
*/



class Solution {
private:
    unordered_map<int,int> cache;
public:
    void add(int num){
        cache[num]++;
    }
    bool find(int value){
        for(unordered_map<int,int>:: iterator it = cache.begin(); it!=cache.end(); it++){
            int i = it->first;
            int j = value-i;
            if((i==j && cache[i]>1) || (i!=j && cache.find(j)!=cache.end()))
                return true;
        }
        return false;
    }
};






