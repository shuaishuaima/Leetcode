//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Design a hit counter which counts the number of hits received in the past 5 minutes.
 
 Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.
 
 It is possible that several hits arrive roughly at the same time.
 
 Example:
 HitCounter counter = new HitCounter();
 
 // hit at timestamp 1.
 counter.hit(1);
 
 // hit at timestamp 2.
 counter.hit(2);
 
 // hit at timestamp 3.
 counter.hit(3);
 
 // get hits at timestamp 4, should return 3.
 counter.getHits(4);
 
 // hit at timestamp 300.
 counter.hit(300);
 
 // get hits at timestamp 300, should return 4.
 counter.getHits(300);
 
 // get hits at timestamp 301, should return 3.
 counter.getHits(301);
 Follow up:
 What if the number of hits per second could be very large? Does your design scale?

 
 
 */

#include <iostream>
#include <vector>
#include <utility>


class HitCounter{
private:
    queue<int> que;
    
public:
    HitCounter() {}
    
    void hit(int timestramp){
        que.push(timestramp);
    }
    
    int getHits(int timestramp){
        while(!que.empty() && timestramp-que.front()>=300){
            que.pop();
        }
        return (int)que.size();
        
    }
};


//follow up

class HitCounter{
private:
    vector<int> times, hits;
public:
    HitCounter(){
        times.resize(300);
        hits.resize(300);
    }
    
    void hit(int timestramp){
        int index = timestramp%300;
        if(times[index]!=timestramp){
            times[index] = timestramp;
            hits[index] = 1;
        }
        else hits[index]++;
    }
    
    int getHits(int timestramp){
        int cnt = 0;
        for(int i = 0; i<300; i++){
            if(timestramp-times[i]<300)
                cnt += hits[i];
        }
        return cnt;
    }
};








