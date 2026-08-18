/*
https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/?envType=daily-question&envId=2026-08-18
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mpp;

        for(auto it : nums){
            mpp[it]++;
        }
        if(k == n){
            return *max_element(nums.begin(), nums.end());
        }
        if(k == 1){
            sort(nums.rbegin(), nums.rend());
            for(int i = 0; i < nums.size(); i++){
                if(mpp[nums[i]] == 1){
                    return nums[i];
                }
            }
            return -1;
        }
        int val1 = nums[0];
        int val2 = nums[n-1];

        if(mpp[val1] > 1 && mpp[val2] > 1){
            return -1;
        }
        else if(mpp[val1] > 1 && mpp[val2] == 1){
            return val2;
        }
        else if(mpp[val1] == 1 && mpp[val2] > 1){
            return val1;
        }
        return max(val1, val2);
    }
};