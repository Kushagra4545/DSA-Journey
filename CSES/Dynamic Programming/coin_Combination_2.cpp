#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int helper(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp){
    if(sum == 0){
        return 1;
    }
    if(idx < 0 || sum < 0){
        return 0;
    }
    if(dp[idx][sum] != -1){
        return dp[idx][sum];
    }
    int take = 0; 
    if(sum >= nums[idx]){
        take = helper(idx, sum - nums[idx], nums, dp);
    }
    int notTake = helper(idx -1, sum, nums, dp);
    
    return dp[idx][sum] = (take + notTake) % MOD;
}
int helperTab(vector<int>nums, vector<vector<int>>& dp, int sum){
    int n = nums.size();
    for(int i =0; i < n; i++){
        dp[i][0] = 1;
    }

    for(int i = 1; i <= sum ; i++){
        if(i % nums[0] == 0){
            dp[0][i] = 1;
        }
        else {
            dp[0][i] = -1;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= sum; j++){
            int take = 0; 
            if(j >= nums[i]){
                if(dp[i][j - nums[i]] != -1)
                    take = dp[i][j - nums[i]];
            }
            int notTake = 0;
            if(dp[i -1][j] != -1)
                notTake = dp[i -1][j];

            dp[i][j] = (take + notTake) % MOD;
        }
    }
    int ways = dp[n-1][sum] % MOD;
    if(ways == -1){
        return 0;
    }
    return ways;
}
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;

    vector<int>nums(n);

    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    vector<vector<int>>dp(n, vector<int>(x + 1, -1));

    int ways = helperTab(nums, dp, x) % MOD;
    cout<<ways;
}