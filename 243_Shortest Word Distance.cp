//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 
 For example,
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 
 Given word1 = "coding", word2 = "practice", return 3.
 Given word1 = "makes", word2 = "coding", return 1.
 
 Note:
 You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 
 
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;




//243 Shortest word distance
int shortest(vector<string>& words, string word1, string word2){
    int minlen= INT_MAX, idx1=-1, idx2=-1, n = words.size();
    for(int i= 0; i<n; i++){
        if(words[i]==word1)
            idx1 = i;
        if(words[i]==word2)
            idx2 = i;
        if(idx1!=-1 && idx2!=-1)
            minlen = min(minlen, abs(idx1-idx2));
    }
    return minlen;
}












