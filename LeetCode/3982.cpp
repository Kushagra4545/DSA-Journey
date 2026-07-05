/*
Problem Link - https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/description/


*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxi(int num){
        int maxiRange = INT_MIN;
        int miniRange = INT_MAX;

        while(num > 0){
            int ld = num % 10;
            maxiRange = max(maxiRange, ld);
            miniRange = min(miniRange, ld);
            num = num/10;
        }
        return maxiRange - miniRange;
    }
    int maxDigitRange(vector<int>& nums) {
        vector<int>digitRange;

        for(int i  = 0; i < nums.size(); i++){
            int digit = maxi(nums[i]);
            digitRange.push_back(digit);
        }

        int maxElem = *max_element(digitRange.begin(), digitRange.end());

        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(digitRange[i] >= maxElem){
                sum += nums[i];
            }
        }
        return sum;
    }
};