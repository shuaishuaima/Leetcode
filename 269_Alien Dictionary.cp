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


using namespace std;

/*
 
 Problem Description:
 
 There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, wherewords are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
 
 For example,
 Given the following words in dictionary,
 
 [
 "wrt",
 "wrf",
 "er",
 "ett",
 "rftt"
 ]
 The correct order is: "wertf".
 
 Note:
 
 You may assume all letters are in lowercase.
 If the order is invalid, return an empty string.
 There may be multiple valid order of letters, return any one of them is fine.
 
 */

class Solution{
public:
    
    string alienOrder(vector<string>& words){
        string res;
        if(words.empty()) return res;
        if(words.size()==1) return words[0];
        unordered_map<char, unordered_set<char>> graph = make_graph(words);
        int n = graph.size();
        unordered_map<char,int> degree;
        for(auto gra: graph){
            degree[gra.first] = 0;
            for(auto c: gra.second)
                degree[c]++;
        }
        queue<char> que;
        for(auto deg: degree){
            if(deg.second==0)
                que.push(deg.first);
        }
        for(int i = 0; i<n; i++){
            if(que.empty()) return "";
            char ch = que.front();
            que.pop();
            res += ch;
            for(auto neigh: graph[ch]){
                if(--degree[neigh]==0)
                    que.push(neigh);
            }
        }
        return res;
        
    }
    unordered_map<char, unordered_set<char>> make_graph(vector<string>& words){
        unordered_map<char, unordered_set<char>> graph;
        int n = words.size();
        for(int i = 1; i<n; i++){
            string word1 = words[i-1], word2 = words[i];
            int m = word1.size(), n = word2.size(), l = max(m,n);
            bool found = false;
            for(int j = 0; j<l; j++){
                if(j<m && graph.find(word1[j])==graph.end())
                    graph[word1[j]] = unordered_set<char>();
                
                if(j<n && graph.find(word2[j])==graph.end())
                    graph[word2[j]] = unordered_set<char>();
                
                if(j<m && j<n && word1[j]!=word2[j] && !found){
                    graph[word1[j]].insert(word2[j]);
                    found = true;
                }
            }
        }
        return graph;
    }
};






class Solution{
public:
    string alianOrder(vector<string>& words){
        if(words.empty()) return "";
        if(words.size()==1) return words[0];
        int n = words.size();
        unordered_map<char,unordered_set<char>> cache;
        generateCache(cache, words);
        int n = cache.size();
        unordered_map<char,int> degree;
        for(auto ca: cache){
            if(!degree[ca.first]);
            for(auto c: ca.second)
                degree[c]++;
        }
        queue<char> que;
        for(auto de: degree){
            if(de.second==0)
                que.push(de.first);
        }
        string res;
        for(int i = 0; i<n; i++){
            if(que.empty()) return "";
            char c = que.front();
            que.pop();
            res += c;
            for(char s: cache[c]){
                if(--degree[s]==0)
                    que.push(s);
            }
        }
        return res;
        
    }
    void generateCache(unordered_map<char,unordered_set<char>>& cache, vector<string>& words({
        for(int i = 1; i<words.size(); i++){
            string word1 = words[i-1];
            string word2 = words[i];
            int m = word1.size(), n = word2.size(), l = max(m,n);
            bool isFound = false;
            for(int j = 0; j<l; j++){
                if(j<m && cache.find(word1[j])==cache.end())
                    cache[word1[j]] = unordered_set<char>();
                if(j<n && cache.find(word2[j])==cache.end())
                    cache[word2[j]] = unordered_set<char>();
                if(j<m && j<n && word1[j]!=word2[j] && !isFound){
                    cache[word1[j]].insert(word2[j]);
                    isFound = true;
                }
            }
        }
        return cache;
    }
};





















