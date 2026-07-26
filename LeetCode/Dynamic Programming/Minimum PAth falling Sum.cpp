/*
Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/description/


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n = matrix.size();
        int m = matrix[0].size();

        if(row >= n){
            return 0;
        }
        if(dp[row][col] != INT_MIN){
            return dp[row][col];
        }
        int case1 = INT_MAX;
        if(col > 0){
            case1 = matrix[row][col] + helper(row+1, col-1, matrix, dp);
        }
        int case2 = matrix[row][col] + helper(row + 1, col, matrix, dp);

        int case3 = INT_MAX;
        if(col < m-1){
            case3 = matrix[row][col] + helper(row+1, col+1, matrix, dp);
        }

        return dp[row][col] = min({case1, case2, case3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, INT_MIN));

        int maxi = INT_MAX;
        for(int i = 0; i < m; i++){
            int cost = helper(0, i, matrix, dp);
            maxi = min(maxi, cost);
        }
        return maxi;
    }
};