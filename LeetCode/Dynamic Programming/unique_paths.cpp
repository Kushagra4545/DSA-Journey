#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& dp){
        if(m == 0 && n == 0){
            return 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int left = 0;
        if(n > 0){
            left += helper(m, n-1, dp);
        }
        int right = 0;
        if(m > 0){
            right += helper(m-1, n, dp);
        }
        return dp[m][n] = left + right;
    }
    int helperTab(int m, int n, vector<vector<int>>& dp){
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        //return helper(m-1, n-1, dp);
        return helperTab(m, n, dp);
    }
};