/*
Problem Link - https://www.geeksforgeeks.org/problems/rotation4723/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumSortedArray(vector<int>& nums){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = INT_MAX;
        
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
    int findIdx(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[low]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            else if(nums[mid] <= nums[high]){
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
    int findKRotation(vector<int> &arr) {
        // int target = minimumSortedArray(arr);
        // return findIdx(arr, target);
        
        int low = 0;
        int high = arr.size() -1;
        
        while(low < high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] > arr[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};
