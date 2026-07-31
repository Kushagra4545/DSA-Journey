#include<bits/stdc++.h>
using namespace std;

int helper(int n, vector<int>& dp){
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int mini = INT_MAX;

    int take = INT_MAX;

    int temp = n;

    while(temp > 0){
        int ld = temp % 10;
        if(ld != 0){
            take = 1 + helper(n-ld, dp);
        }
        temp = temp/10;
        mini = min(mini, take);
    }

    return dp[n] = mini;
}
int helperTab(int n, vector<int>& dp){
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int mini = INT_MAX;

        int take = INT_MAX;

        int temp = i;

        while(temp > 0){
            int ld = temp % 10;
            if(ld != 0){
                take = 1 + dp[i-ld];
            }
            temp = temp/10;
            mini = min(mini, take);
        }
        dp[i] = mini;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;

    vector<int>dp(n+1, -1);
    cout<<helperTab(n, dp);
}