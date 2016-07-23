//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 
    This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
 */

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

int shortest(vector<string>& words, string word1, string word2);

int main(int argc, const char * argv[]) {
    
    return 0;
}

int shortest(vector<string>& words, string word1, string word2){
    int dist = INT_MAX, idx1 = -1, idx2 = -1;
    for(int i = 0; i < words.size(); i++){
        if(word1 == word2){
            if(words[i]==word1){
                if(idx1<idx2)
                    idx1 = i;
                else idx2 = i;
            }
        }
        else {
            if(words[i]==word1) idx1 = i;
            if(words[i]==word2) idx2 = i;
        }
        if(idx1!=-1 && idx2!=-1)
            dist = min(dist, abs(idx1-idx2));
    }
    return dist;
}



















