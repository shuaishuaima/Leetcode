//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>


using namespace std;

/*
 
 Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
 You may assume each number in the sequence is unique.
 Follow up:
 Could you do it using only constant space complexity?
 
*/

class Solution{
public:
    //using stack O(n) space complexity
    bool verify(vector<int>& preorder){
        int low = INT_MIN;
        stack<int> stack;
        for(auto p: preorder){
            if(p<low)
                return false;
            while(!stack.empty() && stack.top()<p){
                low = stack.top();
                stack.pop();
            }
            stack.push(p);
        }
        return true;
    }
     // same idea with above method, using constant space
    
    /*
            bool verify(vector<int>& preorder){
                int low = INT_MIN, i = -1;
                for(auto p: preorder){
                    if(p<low)
                        return false;
                    while(i>=0 && p>preorder[i]){
                        low = preorder[i--];
                    }
                    preorder[++i] = p;
                }
                return true;
            }
     
    */
    
    // Divide and Conquer
    bool verify1(vector<int>& preorder){
        if(preorder.empty()) return true;
        return helper(preorder, 0, preorder.size()-1);
    }
    
    bool helper(vector<int>& preorder, int start, int end){
        if(start>=end) return true;
        int pivot = preorder[start];
        int bigger = -1;
        for(int i = start+1; i<=end; i++){
            if(bigger == -1 && preorder[i]>pivot) bigger = i;
            if(bigger!=-1 && preorder[i]<pivot) return false;
        }
        if(bigger==-1)
            return helper(preorder, start+1, end);
        else return helper(preorder, start+1, bigger-1)&&helper(preorder, bigger, end);
    }
    
    
    

};






















