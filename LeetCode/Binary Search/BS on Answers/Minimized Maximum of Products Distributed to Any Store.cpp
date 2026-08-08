#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<int>& nums, int threshold, int mid){
        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            count += (nums[i] + mid - 1)/mid;
            if(count > threshold) return false;
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& nums) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isSafe(nums, n, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};