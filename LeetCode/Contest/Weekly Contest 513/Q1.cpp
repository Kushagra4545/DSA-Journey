/*
Problem Link - https://leetcode.com/problems/maximize-pair-strength-using-gcd/description/


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxi = LLONG_MIN;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int val1 = nums[i];
                int val2 = nums[j];

                long long mul = 1LL * nums[i] * nums[j];
                int gcdOfNum = __gcd(val1, val2);
                long long den = 1LL * (1LL* gcdOfNum*gcdOfNum);

                maxi = max(maxi, mul/den);
            }
        }
        return maxi;
    }
};