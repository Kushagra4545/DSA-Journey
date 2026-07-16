/*
Problem Link : https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/

Time = O(nLog(n));
Space = O(n);
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd;
        int mx = nums[0];
        for(int i = 0;i<n;i++){
            mx = max(mx,nums[i]);
            int prefix = __gcd(nums[i],mx);
            prefixGcd.push_back(prefix);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        vector<int>pairs;
        int i = 0;
        int j = prefixGcd.size()-1;
        while(i < j){
            int elem = __gcd(prefixGcd[i],prefixGcd[j]);
            pairs.push_back(elem);
            i++;
            j--;
        }
        long long sum = 0;
        for(int i = 0;i<pairs.size();i++){
            sum += pairs[i];
        }
        return sum;
    }
};