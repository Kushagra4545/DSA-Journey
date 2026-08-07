/*
Problem Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[low] <= nums[mid]){
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else if(nums[mid] <= nums[high]){
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};