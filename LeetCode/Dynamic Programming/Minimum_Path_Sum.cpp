#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//recursive
    int helperRecursive(int row, int col, vector<vector<int>>& grid){
        if(row == 0 && col == 0){
            return grid[0][0];
        }
        if(row < 0 || col < 0) return INT_MAX;
        int leftSum = INT_MAX;
        if(col > 0){
            leftSum = grid[row][col] + helperRecursive(row, col-1, grid);
        }
        int upSum = INT_MAX;
        if(row > 0){
            upSum = grid[row][col] + helperRecursive(row-1, col, grid);
        }
        return min(leftSum, upSum);
    }
    //Memoized Approach
    int helperMemo(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(row == 0 && col == 0){
            return grid[row][col];
        }
        if(row < 0 || col < 0){
            return INT_MAX;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int leftSum = INT_MAX;
        if(col > 0){
            leftSum = grid[row][col] + helperMemo(row, col-1, grid, dp);
        }
        int upSum = INT_MAX;
        if(row > 0){
            upSum = grid[row][col] + helperMemo(row-1, col, grid, dp);
        }

        return dp[row][col] = min(leftSum, upSum);
    }
    //Tabulation Approach
    int helperTab(vector<vector<int>>& grid, vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i = 1; i < m; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                int leftSum = grid[i][j] + dp[i][j-1];
                int upSum = grid[i][j] + dp[i-1][j];

                dp[i][j] = min(leftSum, upSum);
            }
        }
        return dp[n-1][m-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //return helper(n-1, m-1, grid);
        vector<vector<int>>dp(n, vector<int>(m, 0));
        //return helperMemo(n-1, m-1, grid, dp);
        return helperTab(grid, dp);
    }
};