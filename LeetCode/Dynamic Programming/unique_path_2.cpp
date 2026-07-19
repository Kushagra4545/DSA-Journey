#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(m == 0 && n == 0){
            return 1;
        }
        if(obstacleGrid[m][n] == 1){
            return 0;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int left = 0;
        if(n > 0){
            left += helper(m, n-1, obstacleGrid, dp);
        }
        int right = 0;
        if(m > 0){
            right += helper(m-1, n, obstacleGrid, dp);
        }
        return dp[m][n] = left + right;
    }
    int helperTab(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 1){
                dp[i][0] = 0;
                break;
            }
            else{
                dp[i][0] = 1;
            }
        }

        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == 1){
                dp[0][i] = 0;
                break;
            }
            else{
                dp[0][i] = 1;
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1){
            return 0;
        }
        vector<vector<int>>dp(m, vector<int>(n, 0));
        //return helper(m-1, n-1, obstacleGrid, dp);
        return helperTab(obstacleGrid, dp);
    }
};