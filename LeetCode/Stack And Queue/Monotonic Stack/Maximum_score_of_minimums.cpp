/*
Problem Link - https://leetcode.com/problems/maximum-score-of-a-good-subarray/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans; 
    }
    vector<int> prevSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int>ans(n);
        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>nextSmall = nextSmaller(nums);
        vector<int>prevSmall = prevSmaller(nums);

        int score = INT_MIN;

        for(int i = 0; i < n; i++){
            int left = prevSmall[i] + 1;
            int right = nextSmall[i] - 1;

            if(left <= k && k <= right){
                score = max(score, (right-left+1)*nums[i]);
            }
        }
        return score;
    }
};