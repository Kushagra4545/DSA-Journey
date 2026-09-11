#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int prefixSum = 0;

        unordered_map<int, int>mpp;

        int count = 0;

        for(int i = 0; i < nums.size(); i++){
            mpp[prefixSum]++;
            prefixSum += nums[i];
            int toFind = prefixSum - k;
            if(mpp.find(toFind) != mpp.end()){
                count += mpp[toFind];
            }
        }
        return count;
    }
};