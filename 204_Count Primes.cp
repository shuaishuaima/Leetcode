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
 
 
 Count the number of prime numbers less than a non-negative number, n.
 
 

 
*/


//The Sieve of Eratosthenes uses an extra O(n) memory and its runtime complexity is O(n log log n)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        for(int i = 2; i*i<n; i++){
            if(primes[i]){
                for(int j = i*i; j<n; j = j+i)
                    primes[j] = false;
            }
        }
        int count = 0;
        for(int i = 2; i<n; i++){
            if(primes[i])
                count++;
        }
        return count;
    }
};













