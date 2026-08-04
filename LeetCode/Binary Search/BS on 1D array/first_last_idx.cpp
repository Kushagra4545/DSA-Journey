/*
Problrm Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int>& nums, int target){
        int n = nums.size();
        int ans = -1;

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(target >= nums[mid]){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(ans != -1){
            if(nums[ans] != target) return -1;
        }
        return ans;
    }
    int lowerBound(vector<int>& nums, int target){
        int n = nums.size();

        int ans = -1;

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(ans != -1){
            if(nums[ans] != target) return -1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);

        return {lb, ub};
    }
};