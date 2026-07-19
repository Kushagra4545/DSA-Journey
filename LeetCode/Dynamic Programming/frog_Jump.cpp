#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int helperRecursive(int idx, vector<int>& height){
        if(idx == 0){
            return 0;
        }
        
        int take1 = abs(height[idx-1] - height[idx]) + helperRecursive(idx - 1, height);
        int take2 = INT_MAX;
        if(idx >= 2){
            take2 = abs(height[idx-2] - height[idx]) + helperRecursive(idx - 2, height);
        }
        return min(take1, take2);
    }
    int helperMemo(int idx, vector<int>& height, vector<int>& dp){
        if(idx == 0){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take1 = abs(height[idx-1] - height[idx]) + helperMemo(idx - 1, height, dp);
        int take2 = INT_MAX;
        if(idx >= 2){
            take2 = abs(height[idx-2] - height[idx]) + helperMemo(idx - 2, height, dp);
        }
        return dp[idx] = min(take1, take2);
    }
    
    int helperTab(vector<int>& dp, vector<int>& height){
        dp[0] = 0;
        for(int i = 1; i < height.size(); i++){
            int take1 = abs(height[i-1] - height[i]) + dp[i-1];
            int take2 = INT_MAX;
            if(i >= 2){
                take2 = abs(height[i-2] - height[i]) + dp[i-2];
            }
            dp[i] = min(take2, take1);
        }
        return dp[height.size()-1];
    }
    
    int minCost(vector<int>& height) {
       //return helperRecursive(height.size()-1, height);
       vector<int>dp(height.size(), -1);
       //return helperMemo(height.size()-1, height, dp);
       return helperTab(dp, height);
    }
};