/*
Problem Link - https://leetcode.com/problems/rotate-array/description/\

Time - O(n);
Space = O(1);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(int stIdx, int endIdx, vector<int>& nums){
        while(stIdx < endIdx){
            swap(nums[stIdx], nums[endIdx]);
            stIdx++;
            endIdx--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(0, n-1, nums);
        reverse(0, k-1, nums);
        reverse(k, n-1, nums);
    }
};