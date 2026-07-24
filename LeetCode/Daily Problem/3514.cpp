#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<int> helper(int idx, int count, vector<int>& nums, int xorVal, map<pair<int, pair<int, int>>, set<int>> &dp){
        if(count == 0){
            return {xorVal};
        }
        if(idx < 0){
            return {};
        }
        pair<int, pair<int, int>> state = {idx, {count, xorVal}};

        if(dp.count(state)){
            return dp[state];
        }
        set<int>ans;

        set<int>take = helper(idx, count-1, nums, xorVal ^ nums[idx], dp);

        for(auto it : take){
            ans.insert(it);
        }

        set<int>notTake = helper(idx-1, count, nums, xorVal, dp);

        for(auto it : notTake){
            ans.insert(it);
        }

        return dp[state] = ans;
    }
    int uniqueXorTriplets(vector<int>& nums) {
        // map<pair<int, pair<int, int>>, set<int>>dp;
        // int xorVal = 0;
        // set<int>st = helper(nums.size()-1, 3, nums, xorVal, dp);
        // return st.size();
        // set<int>st;
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i; j < nums.size(); j++){
        //         for(int k = j; k < nums.size(); k++){
        //             int val = nums[i]^nums[j]^nums[k];
        //             st.insert(val);
        //         }
        //     }
        // }
        // return st.size();
        if(nums.size() == 1){
            return 1;
        }

        int MAX = 2048;

        vector<bool>one(MAX, false);
        vector<bool>two(MAX, false);
        vector<bool>three(MAX, false);

        for(int val : nums){
            for(int i = 0; i < MAX; i++){
                if(one[i]){
                    two[val^i] = true;
                }
            }
            one[val] = true;
        }

        for(int val : nums){
            for(int i = 0; i < MAX; i++){
                if(two[i]){
                    three[i^val] = true;
                }
            }
        }
        int ans = 0;
        for(bool exist : three){
            ans += exist;
        }
        return ans;
    }
};