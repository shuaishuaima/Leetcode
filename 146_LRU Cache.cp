45. Jump Game II//
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
 
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 
 
 
 */


class LRUCache{
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()) return -1;
        lists.splice(lists.begin(), lists, cache[key]);
        cache[key] = lists.begin();
        return cache[key]->val;
    }
    
    void set(int key, int value) {
        if(cache.find(key)==cache.end()){
            if(lists.size()==capacity){
                cache.erase(lists.back().key);
                lists.pop_back();
            }
            lists.insert(lists.begin(), ListNode(key, value));
            cache[key] = lists.begin();
        }
        else{
            cache[key]->val = value;
            lists.splice(lists.begin(), lists, cache[key]);
            cache[key] = lists.begin();
        }
    }
private:
    struct ListNode{
        int key;
        int val;
        ListNode(int k, int v): key(k), val(v) {}
    };
    list<ListNode> lists;
    unordered_map<int,list<ListNode>::iterator> cache;
    int capacity;
};







