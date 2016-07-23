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
 
 
 Given a 2D board and a list of words from the dictionary, find all words in the board.
 
 Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 
 For example,
 Given words = ["oath","pea","eat","rain"] and board =
 
 [
 ['o','a','a','n'],
 ['e','t','a','e'],
 ['i','h','k','r'],
 ['i','f','l','v']
 ]
 Return ["eat","oath"].
 Note:
 You may assume that all inputs are consist of lowercase letters a-z.
 
 click to show hint.
 
 You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
 
 If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.
 

 
 

 
*/


class TrieNode{
public:
    bool end;
    int idx;
    TrieNode* child[26];
    TrieNode(){
        end = false;
        idx = -1;
        for(int i = 0; i<26; i++)
            child[i] = nullptr;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.empty() || words.empty()) return res;
        int m = board.size(), n = board[0].size();
        TrieNode* root = buildTrie(words);
        for(int i = 0 ; i<m; i++){
            for(int j = 0; j<n; j++){
                helper(board, i, j, root, words, res);
            }
        }
        return res;
    }
    
    void helper(vector<vector<char>>& board, int row, int col, TrieNode* root, vector<string>& words, vector<string>& res){
        int temp = board[row][col]-'a';
        if(board[row][col]=='#' || root->child[temp]==nullptr) return;
        if(root->child[temp]->end){
            res.push_back(words[root->child[temp]->idx]);
            root->child[temp]->end = false;
        }
        board[row][col] = '#';
        if(row-1>=0) helper(board, row-1, col, root->child[temp], words, res);
        if(col-1>=0) helper(board, row, col-1, root->child[temp], words, res);
        if(row+1<board.size()) helper(board, row+1, col, root->child[temp], words, res);
        if(col+1<board[0].size()) helper(board, row, col+1, root->child[temp], words, res);
        board[row][col] = temp+'a';
    }
    
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        for(int i = 0; i<words.size(); i++){
            buildTrieNode(words, i, root);
        }
        return root;
    }
    void buildTrieNode(vector<string>& words, int index, TrieNode* root){
        TrieNode* p = root;
        for(int i = 0; i<words[index].size(); i++){
            int temp = words[index][i]-'a';
            if(p->child[temp]==nullptr) p->child[temp] = new TrieNode();
            p = p->child[temp];
        }
        p->end = true;
        p->idx = index;
    }
};









