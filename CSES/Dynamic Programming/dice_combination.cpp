#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7; 

int helper(int n, vector<int>& dp){
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    long long ways = 0;
    for(int i = 1; i <= 6; i++){
        ways += helper(n - i, dp) % MOD;
    }
    return dp[n] = ways % MOD;
}
int helperTab(int n){
    vector<int>dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        long long ways = 0;
        for(int j = 1; j <= 6; j++){
            if(i >= j)
                ways += dp[i - j] % MOD;
        }
        dp[i] = ways % MOD;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    
    vector<int>dp(n+1, -1);
    cout<<helperTab(n) % MOD<<endl;
}