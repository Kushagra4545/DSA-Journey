#include<bits/stdc++.h>
using namespace std;

int uniqueXorTriplets(vector<int>& nums) {
        // map<pair<int, pair<int, int>>, set<int>>dp;
        // int xorVal = 0;
        // set<int>st = helper(nums.size()-1, 3, nums, xorVal, dp);
        // return st.size();
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int ans = 1;
        while(ans <= n){
            ans *= 2;
        }
        return ans;
    }