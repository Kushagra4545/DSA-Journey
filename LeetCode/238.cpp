/*
Probolem Link - https://leetcode.com/problems/product-of-array-except-self/description/

Time - O(n);
Space - O(n);
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int withoutZeroMul = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zeroCount++;
            }
            else{
                withoutZeroMul *= nums[i];
            }
        }

        vector<int>ans;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                int newZeroCount = zeroCount - 1;

                if(newZeroCount <= 0){
                    ans.push_back(withoutZeroMul);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                if(zeroCount != 0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(withoutZeroMul/nums[i]);
                }
            }
        }
        return ans;
    }
};