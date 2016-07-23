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
 
 Find the total area covered by two rectilinear rectangles in a 2D plane.
 
 Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 
 Rectangle Area
 Assume that the total area is never beyond the maximum possible value of int.
 

 
*/





class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(left, min(C,G));
        int bottom = max(B,F), top = max(bottom, min(D,H));
        return (D-B)*(C-A)+(G-E)*(H-F)-(right-left)*(top-bottom);
    }
};





