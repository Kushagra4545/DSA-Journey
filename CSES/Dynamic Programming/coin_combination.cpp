#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int helper(int idx, int sum, vector<int>& nums){
    if(sum == 0){
        return 1;
    }
    if(idx < 0 || sum < 0){
        return 0;
    }

    int take = 0;
    if(sum >= nums[idx]){
        take = helper(idx, sum - nums[idx], nums);
    }
    int notTake = helper(idx -1, sum, nums);
    
    return (take + notTake) % MOD;
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

    int ways = helper(n-1, x, nums) % MOD;
    cout<<ways;
}