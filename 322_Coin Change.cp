//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Example 1:
 coins = [1, 2, 5], amount = 11
 return 3 (11 = 5 + 5 + 1)
 
 Example 2:
 coins = [2], amount = 3
 return -1.
 
 Note:
 You may assume that you have an infinite number of each kind of coin.
 
*/

#include <iostream>
#include <vector>
#include <utility>



using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> count(amount+1, amount+1);
        count[0] = 0;
        for(int i = 1; i<=amount; i++){
            for(int j = 0; j<coins.size(); j++){
                if(i>=coins[j])
                    count[i] = min(count[i], count[i-coins[j]]+1);
            }
        }
        return count[amount]==amount+1?-1:count[amount];
    }
};
















