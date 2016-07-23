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
 
 
 Implement a trie with insert, search, and startsWith methods.
 
 Note:
 You may assume that all inputs are consist of lowercase letters a-z.

 
 

 
*/

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
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i<prefix.size(); i++){
            int index = prefix[i]-'a';
            if(p->children[index]==nullptr)
                return false;
            else p = p->children[index];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


