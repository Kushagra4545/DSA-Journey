#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int helper(int sum, vector<int>& nums, vector<int>& dp){
    if(sum == 0){
        return 1;
    }
    if(sum < 0) return 0;
    if(dp[sum] != -1){
        return dp[sum];
    }
    long long ways = 0;
    for(int i = 0; i < nums.size(); i++){
        ways = (ways + helper(sum - nums[i], nums, dp)) % MOD;
    }
    return dp[sum] = ways % MOD;
}
int helperTab(int sum, vector<int>& nums, vector<int>& dp){
    dp[0] = 1;

    for(int i = 1; i <= sum; i++){
        long long ways = 0;
        for(int j = 0; j < nums.size(); j++){
            if(i >= nums[j]){
                ways += dp[i - nums[j]];
            }
        }
        dp[i] = ways % MOD;
    }
    if(dp[sum] != -1){
        return dp[sum];
    }
    return 0;
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

    vector<int>dp(x + 1, -1);
    int ways = helperTab(x, nums, dp) % MOD;
    cout<<ways;
}