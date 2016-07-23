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
 
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 
 Return a deep copy of the list.

 
 
 
 */



/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==nullptr) return head;
        RandomListNode* p = head, *copy = nullptr, *nex = nullptr;
        while(p){
            nex = p->next;
            copy = new RandomListNode(p->label);
            copy->next = nex;
            p->next = copy;
            p = nex;
        }
        p = head;
        while(p){
            p->next->random = p->random?p->random->next:nullptr;
            p = p->next->next;
        }
        p = head;
        RandomListNode* copyhead = p?p->next:nullptr;
        while(p){
            copy = p->next;
            p->next = copy->next;
            p = p->next;
            copy->next = p?p->next:nullptr;
        }
        return copyhead;
    }
};




