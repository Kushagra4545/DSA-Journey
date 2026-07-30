#include<bits/stdc++.h>
using namespace std;

int helper(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp){
    if(sum == 0){
        return 0;
    }
    if(idx < 0){
        return INT_MAX;
    }
    if(dp[idx][sum] != -1){
        return dp[idx][sum];
    }
    int take = INT_MAX;
    if(sum >= nums[idx]){
        int temp = helper(idx, sum - nums[idx], nums, dp);
        if(temp != INT_MAX){
            take = 1 + temp;
        }
    }
    int notTake = helper(idx-1, sum, nums, dp);

    return dp[idx][sum] = min(take, notTake);
}
int helperTab(vector<int>& nums, vector<vector<int>>& dp, int sum){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        dp[i][0] = 0;
    }

    for(int j = 1; j <= sum; j++){
        if(j % nums[0] == 0){
            dp[0][j] = j/nums[0];
        }
        else{
            dp[0][j] = -1;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= sum; j++){
            int take = INT_MAX;
            if(j >= nums[i]){
                int temp = dp[i][j - nums[i]];
                if(temp != -1){
                    take = 1 + temp;
                }
            }
            int notTake = INT_MAX;
            if(dp[i-1][j] != -1){
                notTake = dp[i-1][j];
            }

            int ans = min(take, notTake);

            if(ans == INT_MAX){
                dp[i][j] = -1;
            }
            else{
                dp[i][j] = ans;
            }
        }
    }
    return dp[n-1][sum];
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

    int val = helperTab(nums, dp, x);

    if(val == 0){
        cout<<-1<<endl;
    }
    else{
        cout<<val<<endl;
    }
}