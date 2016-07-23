//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 Given a non-negative number represented as a singly linked list of digits, plus one to the number.
 
 The digits are stored such that the most significant digit is at the head of the list.
 
 Example:
 Input:
 1->2->3
 
 Output:
 1->2->4
 
 */

#include <iostream>
#include <vector>
#include <utility>


class Solution {
public:
    ListNode* plusOne(ListNode* head){
        ListNode* cur = head, *right = nullptr;
        while(cur){
            if(cur->val!=9) right = cur;
            cur = cur->next;
        }
        if(!right){
            right = new ListNode(0);
            right->next = head;
            head = right;
        }
        right->val++;
        cur = right->next;
        while(cur){
            cur->val = 0;
            cur = cur->next;
        }
        return head;
    }
};







