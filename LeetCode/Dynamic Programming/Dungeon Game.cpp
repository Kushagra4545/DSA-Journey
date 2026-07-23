#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(row == n-1 && col == m-1){
            return max(1, 1-grid[row][col]);
        }
        if(row >= n || col >= m){
            return INT_MAX;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int leftSum = helper(row, col + 1, grid, dp);
        int downSum = helper(row + 1, col, grid, dp);
        
        int need = min(leftSum, downSum);

        return max(1, need - grid[row][col]);
    }
    
    int helperTab(vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        
        dp[n-1][m-1] = max(1-grid[n-1][m-1], 1);

        for(int i = n-2; i >= 0; i--){
            dp[i][m-1] = max(dp[i+1][m-1] - grid[i][m-1], 1);
        }

        for(int j = m-2; j >= 0; j--){
            dp[n-1][j] = max(1, dp[n-1][j+1] - grid[n-1][j]);
        }

        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                int need = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(1, need - grid[i][j]);
            }
        }
        return dp[0][0];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>>dp(n, vector<int>(m, 0));

        return helperTab(dungeon, dp);
    }
};