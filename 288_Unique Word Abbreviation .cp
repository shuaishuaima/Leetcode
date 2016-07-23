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
#include <queue>


using namespace std;

/*
 
 Problem Description:
 
 An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
 
 a) it                      --> it    (no abbreviation)
 
 1
 b) d|o|g                   --> d1g
 
 1    1  1
 1---5----0----5--8
 c) i|nternationalizatio|n  --> i18n
 
 1
 1---5----0
 d) l|ocalizatio|n          --> l10n
 Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
 
 Example:
 
 Given dictionary = [ "deer", "door", "cake", "card" ]
 
 isUnique("dear") -> false
 isUnique("cart") -> true
 isUnique("cane") -> false
 isUnique("make") -> true
 
*/

class ValidWordAbbr{
private:
    unordered_map<string, string> map;
public:
    ValidWordAbbr(vector<string>& dictionary){
        for(auto dic: dictionary){
            string s = abb(dic);
            if(map.find(s)!=map.end()){
                if(map[s]!=dic)
                    map[s]="";
            }
            map[s]=dic;
        }
    }
    
    bool isUnique(string word){
        string s = abb(word);
        return map.count(s)==0 || map[s]==word;
    }
    string abb(string s){
        int n = s.size();
        if(n<=2) return s;
        else return s[0]+to_string(n-2)+s[n-1];
    }
};
























