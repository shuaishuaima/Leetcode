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
 
 
 Design a data structure that supports the following two operations:
 
 void addWord(word)
 bool search(word)
 search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 
 For example:
 
 addWord("bad")
 addWord("dad")
 addWord("mad")
 search("pad") -> false
 search("bad") -> true
 search(".ad") -> true
 search("b..") -> true
 Note:
 You may assume that all words are consist of lowercase letters a-z.
 

 
 

 
*/


class WordDictionary {
private:
    struct TrieNode{
        bool end;
        TrieNode* child[26];
        TrieNode(){
            end = false;
            for(int i = 0; i<26; i++)
                child[i] = nullptr;
        }
    };
    TrieNode* root;
public:
    WordDictionary(){
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        for(int i = 0; i<word.size(); i++){
            int index = word[i]-'a';
            if(p->child[index]==nullptr) p->child[index] = new TrieNode();
            p = p->child[index];
        }
        p->end = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        TrieNode* p = root;
        return searchWord(word, p, 0);
    }
    
    bool searchWord(string& word, TrieNode* p, int index){
        if(index==word.size()){
            return p->end;
        }
        if(word[index]=='.'){
            for(int i = 0; i<26; i++){
                if(p->child[i]!=nullptr)
                    if(searchWord(word,p->child[i], index+1))
                        return true;
            }
            return false;
        }
        else {
            int temp = word[index]-'a';
            if(p->child[temp]==nullptr) return false;
            else return searchWord(word, p->child[temp], index+1);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");









