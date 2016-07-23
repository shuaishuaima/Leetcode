//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
    This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
 */

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDistance{
private:
    unordered_map<string, vector<int>> map;
public:
    WordDistance(vector<string>& words){
        for(int i = 0; i<words.size(); i++){
            map[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2){
        vector<int> v1 = map[word1];
        vector<int> v2 = map[word2];
        int i = 0, j = 0, minlen = INT_MAX;
        size_t m = v1.size(), n = v2.size();
        while(i<m && j<n){
            minlen = min(minlen, abs(v1[i]-v2[j]));
            if(v1[i]<v2[j])
                i++;
            else j++;
        }
        return minlen;
    }
};






















