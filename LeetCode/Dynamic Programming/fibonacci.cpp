#include<bits/stdc++.h>
using namespace std;

//recursive 
//Time - O(2 ^ n);
//Space - O(n) //recursive stack space 
int fibRecursive(int n){
    if(n <= 1){
        return n;
    }
    return fibRecursive(n-1) + fibRecursive(n-2);
}
//Memoized
//Time - O(n);
//Sapce - O(n) + O(n) //recursive stack space  
int fibMemo(int n, vector<int>& dp){
    if(n <= 1){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = fibMemo(n-1, dp) + fibMemo(n-2, dp);
}
//Tabulation + space Optimization
//Time - O(n);
//Space - O(1);
int fibTab(int n){
    int a = 0;
    int b = 1;
    for(int i = 0; i < n-1; i++){
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
int main(){
    vector<int>dp(7, -1);
    cout<<fibMemo(6, dp);
}