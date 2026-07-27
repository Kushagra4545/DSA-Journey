/*
Problem Link - https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/

Time - O(n);
Space - O(1);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int max1 = INT_MIN;
        for(int i = 0; i < n; i++){
            max1 = max(max1, nums[i]);
        }

        int max2 = INT_MIN;
        int count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == max1 && count < 1){
                count++;
                continue;
            }
            max2 = max(max2, nums[i]);
        }

        return (max1 - 1)*(max2 - 1);
    }
};