//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
 
 For example,
 MovingAverage m = new MovingAverage(3);
 m.next(1) = 1
 m.next(10) = (1 + 10) / 2
 m.next(3) = (1 + 10 + 3) / 3
 m.next(5) = (10 + 3 + 5) / 3
 
*/

#include <iostream>
#include <vector>
#include <utility>



class MovingAverage{
private:
    queue<int> que;
    int sz;
    int sum;
public:
    MovingAverage(int size): sz(size), sum(0){
        que = queue<int>();
    }
    
    double next(int val){
        sum += val;
        que.push(val);
        if(que.size()>sz){
            sum -= que.front();
            que.pop();
        }
        return (double)sum/que.size();
        
    }
};














