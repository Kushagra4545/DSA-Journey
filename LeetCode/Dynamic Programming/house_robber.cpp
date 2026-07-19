#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int helperRecursive(int idx, vector<int>& arr){
        if(idx == 0){
            return arr[idx];
        }
        if(idx < 0){
            return 0;
        }
        int take = arr[idx] + helperRecursive(idx-2, arr);
        int notTake = helperRecursive(idx-1, arr);
        return max(take, notTake);
    }
    int helperMemo(int idx, vector<int>& arr, vector<int>& dp){
        if(idx < 0) return 0;
        if(idx == 0) return arr[idx];
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int take = arr[idx] + helperMemo(idx-2, arr, dp);
        int notTake = helperMemo(idx-1, arr, dp);
        return dp[idx] = max(take, notTake);
    }
    int helperTab(vector<int>& arr, vector<int>& dp){
        int n = arr.size();
        dp[0] = arr[0];
        for(int i = 1; i < n; i++){
            int take = arr[i];
            if(i > 1){
                take += dp[i-2];
            }
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>dp(n, -1);
        //return helperMemo(n-1, arr, dp);
        return helperTab(arr, dp);
    }
};