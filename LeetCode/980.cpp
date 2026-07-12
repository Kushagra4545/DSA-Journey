/*
Problem Link - https://leetcode.com/problems/unique-paths-iii/description/

Time - O(4^k)
where k is number of obstacle

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;

    void bactracking(int r, int c, vector<vector<int>>& grid, int remain){
        int m = grid.size();
        int n = grid[0].size();

        int delRow[4] = {+1, 0, -1, 0};
        int delCol[4] = {0, +1, 0, -1};

        if(r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == -1){
            return;
        }

        if(grid[r][c] == 2){
            if(remain == 1){
                ans++;
            }
            return;
        }

        int temp = grid[r][c];
        grid[r][c] = -1;

        for(int i = 0; i < 4; i++){
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            bactracking(newRow, newCol, grid, remain-1);
        }

        grid[r][c] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int remain = 0;
        int r, c;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    r = i;
                    c = j;
                }
                if(grid[i][j] != -1){
                    remain++;
                }
            }
        }
        bactracking(r, c, grid, remain);
        return ans;
    }
};