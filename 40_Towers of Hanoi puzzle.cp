//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class Solution {
private:
    int step = 0;
public:
    void solve(int n, string srcTower, string intermediateTower, string destTower){
        if(n==1){
            step += 1;
            return;
        }
        solve(n-1, srcTower, destTower, intermediateTower);
        solve(1, srcTower, intermediateTower, destTower);
        solve(n-1, intermediateTower, srcTower, destTower);
    }
};

























