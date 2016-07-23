//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 
 
 */

#include <iostream>
#include <vector>
#include <utility>



class TrieNode {
public:
    // Initialize your data structure here.
    bool isEnd;
    TrieNode* children[26];
    TrieNode() {
        isEnd = false;
        for(int i = 0; i<26; i++)
            this->children[i] = nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    string prefixMatching(string word){
        string res, temp;
        TrieNode* p = root;
        for(int i = 0; i<word.size(); i++){
            int index = word[i]-'a'
            if(p->children[i]==nullptr)
                return res;
            else{
                temp += word[i];
                p = p->children[index];
                if(p->isEnd)
                    res = temp;
            }
        }
        return res;
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i<word.size(); i++){
            int index = word[i]-'a';
            if(p->children[index]==nullptr)
                p->children[index] = new TrieNode();
            p = p->children[index];
        }
        p->isEnd = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i<word.size(); i++){
            int index = word[i]-'a';
            if(p->children[index]==nullptr)
                return false;
            else p = p->children[index];
        }
        return p->isEnd;
    }
    
    
private:
    TrieNode* root;
};



























