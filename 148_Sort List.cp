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
 
 Sort a linked list in O(n log n) time using constant space complexity.
 
 
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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* fast = head, *slow = head, *pre = nullptr;
        while(fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = nullptr;
        ListNode* n1 = sortList(head);
        ListNode* n2 = sortList(slow);
        return merge(n1, n2);
    }
    ListNode* merge(ListNode* n1, ListNode* n2){
        if(n1==nullptr) return n2;
        if(n2==nullptr) return n1;
        if(n1->val < n2->val){
            n1->next = merge(n1->next, n2);
            return n1;
        }
        else {
            n2->next = merge(n1, n2->next);
            return n2;
        }
    }
};





