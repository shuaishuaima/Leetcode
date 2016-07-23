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
    
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 
 You may not alter the values in the nodes, only nodes itself may be changed.
 
 Only constant memory is allowed.
 
 For example,
 Given this linked list: 1->2->3->4->5
 
 For k = 2, you should return: 2->1->4->3->5
 
 For k = 3, you should return: 3->2->1->4->5


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        int len = 0;
        while(p->next){
            p = p->next;
            len++;
        }
        p = &dummy;
        while(len>=k){
            ListNode* cur = p->next;
            for(int i = 0; i<k-1; i++){
                ListNode* nex = cur->next;
                cur->next = nex->next;
                nex->next = p->next;
                p->next = nex;
            }
            p = cur;
            len -= k;
        }
        return dummy.next;
    }
};