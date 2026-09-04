#include<bits/stdc++.h>
using namespace std;

/* ----------- KADANES ALGORITHM---------- */

int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MIN;
        int sum = 0;

        for(int i = 0; i < n; i++){
            if(sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }