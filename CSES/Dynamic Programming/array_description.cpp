#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int helper(int idx, int prev, vector<int>& nums, int m, vector<vector<int>>& dp){
    if(idx < 0) {
        return 1;
    }
    if(dp[idx][prev] != -1){
        return dp[idx][prev];
    }
    long long ans = 0;

    if(nums[idx] != 0){
        if(abs(prev - nums[idx]) <= 1){
            ans = helper(idx - 1, nums[idx], nums, m, dp);
        }
        else{
            ans = 0;
        }
    }
    else{
        for(int i = 1; i <= m; i++){
            if(abs(prev - i) <= 1){
                ans = (ans + helper(idx - 1, i, nums, m, dp)) % MOD;
            }
        }
    }

    return dp[idx][prev] = ans % MOD;
}

void helperTab(int n, int m, vector<int>& nums){

    vector<vector<int>> dp(n, vector<int>(m+1,0));

    // Base case
    for(int prev=1; prev<=m; prev++){

        if(nums[0]!=0){

            if(abs(nums[0]-prev)<=1)
                dp[0][prev]=1;

        }else{

            for(int x=max(1,prev-1);
                x<=min(m,prev+1);
                x++){

                dp[0][prev]=(dp[0][prev]+1)%MOD;
            }
        }
    }

    // Fill DP table
    for(int idx=1; idx<n; idx++){

        for(int prev=1; prev<=m; prev++){

            if(nums[idx]!=0){

                if(abs(nums[idx]-prev)<=1)
                    dp[idx][prev]=dp[idx-1][nums[idx]];

            }else{

                for(int x=max(1,prev-1);
                    x<=min(m,prev+1);
                    x++){

                    dp[idx][prev]=(dp[idx][prev]+dp[idx-1][x])%MOD;
                }
            }
        }
    }

    long long ans=0;

    if(nums[n-1]!=0){

        ans=dp[n-2][nums[n-1]];

    }else{

        for(int x=1;x<=m;x++)
            ans=(ans+dp[n-2][x])%MOD;
    }

    cout<<ans;
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int>nums(n);
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    if(n == 1){
        if(nums[0] == 0){
            cout<<m;
        }
        else {
            cout<<1;
        }
        return 0;
    }

    vector<vector<int>>dp(n, vector<int>(m + 1, -1));
    //long long ans = 0;

    // if(nums[n-1] == 0){
    //     for(int i = 1; i <= m; i++){
    //         ans = (ans + helper(n-2, i, nums, m, dp)) % MOD;
    //     }
    // }
    // else {
    //     ans = helper(n-2, nums[n-1], nums, m, dp);
    // }
    // cout<<ans;

    helperTab(n, m, nums);
}