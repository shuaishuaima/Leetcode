//
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
 Discription:
    
 You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
 */


//iteration
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode dummy(0);
        ListNode* p = &dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            p->next = new ListNode(sum%10);
            p = p->next;
            carry = sum/10;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        return dummy.next;
    }
};



//recursion

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return helper(l1, l2, 0);
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int carry){
        if(l1==nullptr && l2==nullptr){
            if(carry == 1)
                return new ListNode(carry);
            return nullptr;
        }
        int val1 = l1==nullptr?0:l1->val;
        int val2 = l2==nullptr?0:l2->val;
        int sum = val1+val2+carry;
        carry = (val1+val2+carry)/10;
        ListNode* head = new ListNode(sum%10);
        ListNode* next1 = l1==nullptr?nullptr:l1->next;
        ListNode* next2 = l2==nullptr?nullptr:l2->next;
        head->next = helper(next1, next2, carry);
        return head;
    }
};






