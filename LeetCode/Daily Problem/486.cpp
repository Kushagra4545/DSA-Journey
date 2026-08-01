/*
Problem Link - https://leetcode.com/problems/predict-the-winner/description/

Time - O(n^2);
Space - O(n^2);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];

        int left = nums[i] - helper(i + 1, j, nums, dp);
        int right = nums[j] - helper(i, j-1, nums, dp);
    
        return dp[i][j] = max(left, right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int val = helper(0, nums.size()-1, nums, dp);
        if(val >= 0) return true;
        return false;
    }
};