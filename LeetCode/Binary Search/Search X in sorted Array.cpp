/*
Problem Link = https://leetcode.com/problems/binary-search/description/

Time = O(logn);
Space = O(1);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        if(nums.size() == 1){
            if(target== nums[0]) return 0; 
        }

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }

        return -1;
    }
};