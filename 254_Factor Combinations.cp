//
//  main.cpp
//  chang
//
//  Created by Changjie Ma on 3/17/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//

/*
 
 Numbers can be regarded as product of its factors. For example,
 
 8 = 2 x 2 x 2;
 = 2 x 4.
 Write a function that takes an integer n and return all possible combinations of its factors.
 
 Note:
 
 Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
 You may assume that n is always positive.
 Factors should be greater than 1 and less than n.
 
 
 Examples:
 input: 1
 output:
 
 []
 input: 37
 output:
 
 []
 input: 12
 output:
 
 [
 [2, 6],
 [2, 2, 3],
 [3, 4]
 ]
 input: 32
 output:
 
 [
 [2, 16],
 [2, 2, 8],
 [2, 2, 2, 4],
 [2, 2, 2, 2, 2],
 [2, 4, 4],
 [4, 8]
 ]
 
 
*/

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution{
public:
    vector<vector<int>> factor(int num){
        vector<vector<int>> result;
        vector<int> temp;
        helper(result, temp, num);
        return result;
    }
    void helper(vector<vector<int>>& result, vector<int>& temp, int num){
        int i = temp.empty()?2:temp.back();
        for(;i*i<=num; i++){
            if(num%i==0){
                temp.push_back(i);
                temp.push_back(num/i);
                result.push_back(temp);
                temp.pop_back();
                helper(result, temp, num/i);
                temp.pop_back();
            }
        }
    }
    
   
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<vector<int>> result = solution.factor(32);
    for(auto res: result){
        for(auto re: res)
            cout << re << " ";
        cout << endl;
    }
    return 0;
}





























