/*
Problem Link - https://leetcode.com/problems/first-missing-positive/


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mpp;

        long long maxi = 1;

        for(auto it : nums){
            maxi = max({it*1LL, maxi});
            mpp[it]++;
        }
        
        for(long long i = 1; i <= 1LL*(maxi + 1); i++){
            if(mpp.find(i) == mpp.end()){
                return i;
            }
        } 
        return -1;
    }
};