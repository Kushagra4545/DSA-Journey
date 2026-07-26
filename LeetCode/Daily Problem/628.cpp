/*
Problem Link - https://leetcode.com/problems/maximum-product-of-three-numbers/description/

Time Complexity - O(nlog(n));
Space Complexity - O(1);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    //Was Thinking of triplet Recursion Approach
    
    int helper(int idx, int count, vector<int>& nums, vector<vector<int>>& dp){
        if(count == 0){
            return 1;
        }
        if(idx < 0){
            return INT_MIN;
        }
        if(dp[idx][count] != -1){
            return dp[idx][count];
        }
        int temp = helper(idx-1, count-1,nums, dp);
        int take = INT_MIN;
        if(temp != INT_MIN){
            take = nums[idx] * temp;
        }
        int notTake = helper(idx-1, count, nums, dp);

        return dp[idx][count] = max(take, notTake);
    }
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n, vector<int>(4, -1));
        // return helper(n-1, 3, nums, dp);
        sort(nums.begin(), nums.end());
        int case1 = nums[0] * nums[1] * nums[n-1];
        int case2 = nums[n-1] * nums[n-2] * nums[n-3];

        return max(case1, case2);
    }
};