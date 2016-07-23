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
 
 Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 
 Only one letter can be changed at a time
 Each intermediate word must exist in the word list
 For example,
 
 Given:
 beginWord = "hit"
 endWord = "cog"
 wordList = ["hot","dot","dog","lot","log"]
 As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5.
 
 Note:
 Return 0 if there is no such transformation sequence.
 All words have the same length.
 All words contain only lowercase alphabetic characters.
 

 

 
 
 
 */



class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        wordList.erase(beginWord);
        wordList.erase(endWord);
        int dist = 2;
        while(!head.empty() && !tail.empty()){
            if(head.size()<=tail.size()){
                phead = &head;
                ptail = &tail;
            }
            else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for(auto it = phead->begin(); it!=phead->end(); it++){
                string word = *it;
                for(int i = 0; i<word.size(); i++){
                    char letter = word[i];
                    for(int j = 0; j<26; j++){
                        word[i] = 'a'+ j;
                        if(ptail->find(word)!=ptail->end())
                            return dist;
                        if(wordList.find(word)!=wordList.end()){
                            temp.insert(word);
                            wordList.erase(word);
                        }
                    }
                    word[i] = letter;
                }
            }
            dist++;
            swap(temp, *phead);
        }
        return 0;
    }
};






