#include<bits/stdc++.h>
using namespace std;

/*
Problem Link = https://leetcode.com/problems/distinct-subsequences-ii/description/
*/

class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int n, vector<int>& prevIdx, vector<int>& dp){
        if(n <= 0){
            return 1;
        }
        
        if(dp[n] != -1){
            return dp[n];
        }

        long long total = 2LL * solve(n-1, prevIdx, dp);
        long long duplicates = 0;
        if(prevIdx[n - 1] != -1){
            duplicates = solve(prevIdx[n - 1], prevIdx, dp);
        }
        return dp[n] = (total - duplicates + mod) % mod;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int>prevIdx(n, -1);
        vector<int>hash(26, -1);
    
        for(int i = 0; i < n; i++){
            int idx = s[i] - 'a';
            prevIdx[i] = hash[idx];
            hash[idx] = i;
        }

        vector<int>dp(n + 1, -1);
        return (solve(n, prevIdx, dp) - 1 + mod) % mod;
    }
};