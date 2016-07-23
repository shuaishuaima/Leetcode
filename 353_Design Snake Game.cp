//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.
 
 The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
 
 You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.
 
 Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.
 
 When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
 
 Example:
 Given width = 3, height = 2, and food = [[1,2],[0,1]].
 
 Snake snake = new Snake(width, height, food);
 
 Initially the snake appears at position (0,0) and the food at (1,2).
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class SnakeGame{
private:
    int width, height, score;
    vector<pair<int,int>> food, pos;
public:
    SnakeGame(int width, int height, vector<pair<int,int>> food){
        this->width = width;
        this->height = height;
        this->food = food;
        score = 0;
        pos.push_back(make_pair(0,0));
    }
    
    int move(string direction){
        auto head = pos.front(), tail = pos.back();
        pos.pop_back();
        if(direction=="U") --head.first;
        else if(direction=="D") ++head.first;
        else if(direction=="L") --head.second;
        else if(direction=="R") ++head.second;
        if(count(pos.begin(), pos.end(), head) || head.first<0 || head.first>=height || head.second<0 || head.first>=width)
            return -1;
        
        pos.insert(pos.begin(), head);
        
        if(!food.empty() && food.front()==head){
            score++;
            food.erase(food.begin());
            pos.push_back(tail);
        }
        return score;
    }
};








