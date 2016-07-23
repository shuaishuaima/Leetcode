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
 
 Sort a linked list using insertion sort.
 
 
 
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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode dummy(0);
        ListNode* h = &dummy, *pre = &dummy, *cur = head, *nex = nullptr;
        while(cur){
            nex = cur->next;
            if(pre->next!=nullptr && pre->next->val > cur->val) pre = h;
            while(pre->next!=nullptr && pre->next->val < cur->val)
                pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = nex;
        }
        return dummy.next;
    }
};






