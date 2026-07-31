#include<bits/stdc++.h>
using namespace std;

int helper(int idx, int sum, vector<int>& price, vector<int>& pages, vector<vector<int>>& dp){
    if(sum < 0){
        return INT_MIN;
    }
    if(idx < 0){
        if(sum >= 0){
            return 0;
        }
        return INT_MIN;
    }
    if(dp[idx][sum] != -1){
        return dp[idx][sum];
    }
    int take = INT_MIN;
    if(sum >= price[idx]){
        int val = helper(idx-1, sum - price[idx], price, pages, dp);
        if(val != INT_MIN){
            take = pages[idx] + val;
        }
    }
    int notTake = helper(idx - 1, sum, price, pages, dp);

    return dp[idx][sum] = max(take, notTake);
}

int helperTab(int n, int sum, vector<int>& price, vector<int>& pages, vector<vector<int>>& dp){
    for(int i = 0; i < n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= sum; i++){
        if(i >= price[0]){
            dp[0][i] = pages[0];
        }
        else {
            dp[0][i] = 0;
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= sum; j++){
            int take = INT_MIN;
            if(j >= price[i]){
                int val = dp[i-1][j - price[i]];
                if(val != -1){
                    take = pages[i] + val;
                }
            }
            int notTake = INT_MIN;
            if(dp[i - 1][j] != -1){
                notTake = dp[i - 1][j];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    if(dp[n-1][sum] != INT_MIN){
        return dp[n-1][sum];
    }
    return 0;
}

int main(){
    int n;
    cin>>n;

    int x;
    cin>>x;

    vector<int>price(n);
    vector<int>pages(n);

    for(int i = 0; i < n; i++){
        cin>>price[i];
    }
    for(int i = 0; i < n; i++){
        cin>>pages[i];
    }
    vector<vector<int>>dp(n, vector<int>(x+1, -1));
    //int val = helper(n-1, x, price, pages, dp);
    int val = helperTab(n, x, price, pages, dp);
    if(val != INT_MIN){
        cout<<val;
    }
    else{
        cout<<0;
    }
}