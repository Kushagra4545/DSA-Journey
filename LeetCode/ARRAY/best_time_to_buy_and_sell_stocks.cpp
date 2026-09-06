#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int minPrice = nums[0];

        for(int i = 1; i < n; i++){
            ans = max(ans, nums[i] - minPrice);
            minPrice = min(minPrice, nums[i]);
        }
        //if(ans < 0) return 0;
        return ans;
    }
};