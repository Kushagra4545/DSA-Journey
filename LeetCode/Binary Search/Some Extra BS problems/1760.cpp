#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int mid){
        long long count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i]/mid;
            if(nums[i] % mid == 0) count--;
        }
        if(count <= maxOperations) return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(nums, maxOperations, mid)){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};