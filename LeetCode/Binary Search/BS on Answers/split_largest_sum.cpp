#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPossible(vector<int>& nums, int k, long long mid){
        int count = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                count++;
                sum = nums[i];
            }
        }
        if(count <= k){
            return true;
        }
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = -1;

        while(low <= high){
            long long mid = low + (high - low)/2;

            if(isPossible(nums, k, mid)){
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