#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        int prefix = 0;
        unordered_map<int, int>mpp;
        mpp[0] = 1;
        int count = 0;

        for(int i = 0; i < n; i++){
            prefix += nums[i];

            int rem = ((prefix % k) + k) % k;

            if(mpp.find(rem) != mpp.end()){
                count += mpp[rem];
            }
            mpp[rem]++;
        }
        return count;
    }
};