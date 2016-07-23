//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <unordered_set>


using namespace std;

/*
 
 Problem Description:
 
 Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
 
 Examples:
 [2,3,4] , the median is 3
 
 [2,3], the median is (2 + 3) / 2 = 2.5
 
 Design a data structure that supports the following two operations:
 
 void addNum(int num) - Add a integer number from the data stream to the data structure.
 double findMedian() - Return the median of all elements so far.
 For example:
 
 add(1)
 add(2)
 findMedian() -> 1.5
 add(3)
 findMedian() -> 2
 
*/




class MedianFinder {
private:
    priority_queue<int> min, max;
public:
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if(min.empty() || num<min.top())
            min.push(num);
        else max.push(-num);
        
        if(max.size()>min.size()){
            min.push(-max.top());
            max.pop();
        }
        if(min.size()-max.size()>1){
            max.push(-min.top());
            min.pop();
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        if(min.size()>max.size()) return min.top();
        else return (min.top()-max.top())/2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();






















