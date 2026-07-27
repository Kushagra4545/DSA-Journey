/*
Problem Link - https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

Time - O(n^3);
Space - O(n^2);
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(row == n-1){
            return grid[row][col];
        }

        if(row >= n){
            return 0;
        }
        if(dp[row][col] != INT_MIN){
            return dp[row][col];
        }
        int maxi = INT_MAX;

        for(int i = 0; i < m; i++){
            if(i != col){
                int take = grid[row][col] + helper(row + 1, i, grid, dp);
                maxi = min(maxi, take);
            }
        }
        return dp[row][col] = maxi;
    }

    int helperTab(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, INT_MIN));

        for(int i = 0; i < m; i++){
            dp[n-1][i] = grid[n-1][i];
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < m; j++){
                int maxi = INT_MAX;

                for(int k = 0; k < m; k++){
                    if(k != j){
                        int take = grid[i][j] + dp[i + 1][k];
                        maxi = min(maxi, take);
                    }
                }

                dp[i][j] = maxi;
            }
        }

        int maxi = INT_MAX;

        for(int i = 0; i < m; i++){
            maxi = min(maxi, dp[0][i]);
        }
        return maxi;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m, INT_MIN));

        // int mini = helper(0, 0, grid, dp);

        // for(int i = 0; i < m; i++){
        //     mini = min(mini, helper(0, i, grid, dp));
        // }
        // return mini;

        return helperTab(grid);
    }
};