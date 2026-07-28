/*
Problem Link - https://leetcode.com/problems/first-missing-positive/


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Solution2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 1;
        int prev = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] <= 0) continue;

            if(nums[i] == count && prev != nums[i]){
                prev = nums[i];
                count++;
                continue;
            }
            else if(prev == nums[i]){
                continue;
            }
            else if(nums[i] != count){
                return count;
            }
        }
        return count;
    }

    //Time - O(n);
    //SPace = O(n);
    int Solution3(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] < 0 || nums[i] > n + 1){
                nums[i] = 0;
            }
        }

        vector<int>hash(n+2, 0);

        for(int i = 0; i < n; i++){
            hash[nums[i]] = 1;
        }

        for(int i = 1; i < hash.size(); i++){
            if(hash[i] == 0){
                return i;
            }
        }
        return 1;
    }

    //Time - O(MAX * logn);
    //Space - O(n);
    int Solution1(vector<int>& nums) {
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