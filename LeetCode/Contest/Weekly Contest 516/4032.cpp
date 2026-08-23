#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> PrimeFactors(int n){
        vector<int>ans;
        for (long long i = 2; i * i <= n; i++) {
            if(n % i == 0){
                ans.push_back((int)i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        if(n > 1){
            ans.push_back(n);
        }
        return ans;
    }
    int longestSubarray(vector<int>& nums, int k) {
        vector<vector<int>>temp;
        for(int i = 0; i < nums.size(); i++){
            temp.push_back(PrimeFactors(nums[i]));
        }
        map<int, int>mpp;
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while(j < nums.size()){
            vector<int>primeFact = temp[j];
            for(auto it : primeFact){
                mpp[it]++;
            }
            
            while(mpp.size() > k){
                vector<int>primeFac = temp[i];
                for(auto it : primeFac){
                    mpp[it]--;
                    if(mpp[it] == 0){
                        mpp.erase(it);
                    }
                }
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};