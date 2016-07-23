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
 Discription:
    
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 
 You should preserve the original relative order of the nodes in each of the two partitions.
 
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.

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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next == NULL) return head;
        ListNode dummy1(0), dummy2(0);
        ListNode* p1 = &dummy1, *p2 = &dummy2;
        while(head){
            ListNode* &ref = head->val<x?p1:p2;
            ref->next = head;
            ref = ref->next;
            head = head->next;
        }
        p1->next = dummy2.next;
        p2->next = NULL;
        return dummy1.next;
    }
};













