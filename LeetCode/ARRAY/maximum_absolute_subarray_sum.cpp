#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
        int minSum = INT_MAX;
        int maxSum = INT_MIN;
        int sum2 = 0;

        for(int i = 0; i < n; i++){
            int val1 = nums[i];
            int val2 = sum1 + nums[i];

            int a = nums[i];
            int b = sum2 + nums[i];

            int bestEnding = max(val1, val2);
            int worstEnding = min(a, b);

            minSum = min(worstEnding, minSum);
            maxSum = max(maxSum, bestEnding);

            sum1 = bestEnding;
            sum2 = worstEnding;
        }

        return max(abs(maxSum), abs(minSum));
    }
};
