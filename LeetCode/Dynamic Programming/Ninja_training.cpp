#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //Memoized and recursive code
  
    int helper(int idx, int trId, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(idx == 0){
            int maxi = 0;
            for(int i = 0; i < 3; i++){
                if(i != trId){
                    maxi = max(maxi, mat[idx][i]);
                }
            }
            return maxi;
        }
        if(idx < 0){
            return 0;
        }
        if(dp[idx][trId] != -1){
            return dp[idx][trId];
        }
        int ans = 0;
        for(int i = 0; i < 3; i++){
            int take = INT_MIN;
            if(i != trId){
                take = mat[idx][i] + helper(idx-1, i, mat, dp);
            }
            ans = max(ans, take);
        }
        return dp[idx][trId] = ans;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>dp(n, vector<int>(3, -1));
        int ans = 0;
        for(int i = 0; i < 3; i++){
            int a = helper(n-1, i, mat, dp);
            ans = max(ans, a);
        }
        return ans;
    }
};