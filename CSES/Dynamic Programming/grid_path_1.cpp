#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int helper(int row, int col, vector<string>& grid, vector<vector<int>>& dp){
    if(grid[row][col] == '*'){
        return 0;
    }
    if(row == 0 && col == 0){
        return 1;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    int left = 0;
    if(col > 0){
        left += helper(row, col-1, grid, dp);
    }
    int up = 0;
    if(row > 0){
        up += helper(row-1, col, grid, dp);
    }

    return dp[row][col] = (left + up) % MOD;
}
int helperTab(int n, vector<string>& grid, vector<vector<int>>& dp){
    if(grid[0][0] == '.') dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0) continue;
            if(grid[i][j] == '*') continue;
            int left = 0;
            if(j > 0){
                left += dp[i][j-1];
            }
            int up = 0;
            if(i > 0){
                up += dp[i-1][j];
            }
            dp[i][j] = (left + up) % MOD;
        }
    }
    return dp[n-1][n-1];
}
int main(){
    int n;
    cin>>n;

    vector<string>grid(n);

    for(int i = 0; i < n; i++){
        cin>>grid[i];
    }
    vector<vector<int>>dp(n, vector<int>(n, 0));
    cout<<helperTab(n, grid, dp) % MOD;
}