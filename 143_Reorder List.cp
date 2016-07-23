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
 
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 
 You must do this in-place without altering the nodes' values.
 
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

 
 
 
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return;
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p2 = slow->next;
        slow->next = nullptr;
        p2 = reverseList(p2);
        ListNode* p1 = head;
        while(p1->next){
            ListNode* nex = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1->next->next = nex;
            p1 = nex;
        }
        p1->next = p2;
    }
    ListNode* reverseList(ListNode* head){
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next= nullptr;
        return node;
    }
};

