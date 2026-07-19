#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Time - O(2^n);
    //Space - O(n)
    int helperRecursive(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        int take1 = 0;
        if(n >= 1){
            take1 += helperRecursive(n-1);
        }
        int take2 = 0;
        if(n >= 2){
            take2 += helperRecursive(n-2);
        }
        return take1 + take2;
    }
    //TIme - O(n);
    //Space - O(n) + O(n) -> recursive stack space 
    int helperMemo(int n, vector<int>& dp){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int take1 = 0;
        if(n >= 1){
            take1 += helperMemo(n-1, dp);
        }
        int take2 = 0;
        if(n >= 2){
            take2 += helperMemo(n-2, dp);
        }
        return dp[n] = take1 + take2;
    }
    int climbStairs(int n) {
        vector<int>dp(n + 1, -1);
        //return helperMemo(n, dp);
        // dp[0] = 1;
        // dp[1] = 1;
        int a = 1;
        int b = 1;

        for(int i = 2; i <= n; i++){
            int temp = a + b;
            a = b;
            b = temp;
            // dp[i] = dp[i-1] + dp[i-2]; 
        }
        // return dp[n];
        return b;
    }
}; 