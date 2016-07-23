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
 
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 
 return 1->4->3->2->5->NULL.
 
 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || m==n) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p = &dummy;
        for(int i = 0; i<m-1; i++)
            p = p->next;
        ListNode* cur = p->next;
        for(int i = 0; i<n-m; i++){
            ListNode* nex = cur->next;
            cur->next = nex->next;
            nex->next = p->next;
            p->next = nex;
        }
        return dummy.next;
    }
};












