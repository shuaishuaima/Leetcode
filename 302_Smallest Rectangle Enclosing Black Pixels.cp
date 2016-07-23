//
//  main.cpp
//  leetcode
//
//  Created by Changjie Ma on 3/9/16.
//  Copyright © 2016 Changjie Ma. All rights reserved.
//


/*
 
 An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
 
 For example, given the following image:
 
 [
 “0010”,
 “0110”,
 “0100”
 ]
 and x = 0, y = 2,
 Return 6.
 
 
*/

#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class Solution {
public:
    vector<vector<char>> *image;
    int minArea(vector<vector<char>> &iImage, int x, int y) {
        image = &iImage;
        int m = int(image->size()), n = int((*image)[0].size());
        int top = searchRows(0, x, 0, n, true);
        int bottom = searchRows(x + 1, m, 0, n, false);
        int left = searchColumns(0, y, top, bottom, true);
        int right = searchColumns(y + 1, n, top, bottom, false);
        return (right - left) * (bottom - top);
    }
    int searchRows(int i, int j, int low, int high, bool opt) {
        while (i != j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (*image)[mid][k] == '0') ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
    int searchColumns(int i, int j, int low, int high, bool opt) {
        while (i != j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && (*image)[k][mid] == '0') ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
};


