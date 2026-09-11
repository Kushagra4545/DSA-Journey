#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
    
        int minSum = 0;
        int maxSum = 0;
        int res = INT_MIN;

        for(int i = 0; i < n; i++){
            maxSum = max(maxSum + nums[i], nums[i]);
            minSum = min(minSum + nums[i], nums[i]);

            int val1 = maxSum;
            int val2 = totalSum - minSum;
            if(val2 == 0){
                val2 = INT_MIN;
            }

            res = max({res, val1, val2});
        }
        return res;
    }
};