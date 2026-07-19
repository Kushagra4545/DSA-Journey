#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helperRecursive(int idx, vector<int>& heights, int k){
        if(idx == 0){
            return 0;
        }
        int take1 = abs(heights[idx] - heights[idx-1]) + helperRecursive(idx - 1, heights, k);
        int take2 = INT_MAX;

        for(int i = 2; i <= k; i++){
            if(idx >= i){
                take2 = abs(heights[idx] - heights[idx - i]) + helperRecursive(idx - i, heights, k);
            }
        }
        return min(take1, take2);
    }
    int helperMemo(int idx, vector<int>& heights, int k, vector<int>& dp){
        if(idx == 0){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take1 = abs(heights[idx] - heights[idx-1]) + helperRecursive(idx - 1, heights, k);
        int take2 = INT_MAX;

        for(int i = 2; i <= k; i++){
            if(idx >= i){
                take2 = abs(heights[idx] - heights[idx - i]) + helperRecursive(idx - i, heights, k);
            }
        }
        return dp[idx] = min(take1, take2);
    }
    int helperTab(int idx, vector<int>& heights, int k){
        int n = heights.size();
        vector<int>dp(n, -1);

        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int take1 = abs(heights[i-1] - heights[i-2]) + dp[i-1];
            for(int j = 2; j <= k; j++){
                int take2 = INT_MAX;
                if(i >= j){
                    take2 = abs(heights[i-1] - heights[i-j-1]) + dp[i-j];
                }
                dp[i] = min(take1, take2);
            }
        }
        return dp[n];
    }
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        //return helperRecursive(n-1, heights, k);
        
    }
};
