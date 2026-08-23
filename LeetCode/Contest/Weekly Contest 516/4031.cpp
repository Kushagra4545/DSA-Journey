#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int>hash(max(maxi, upper) + 1, 0);
    
        for(auto it : nums){
            hash[it] = 1;
        }

        vector<vector<int>>ans;
        int i = lower;
    
        while(i <= upper) {
            if(hash[i] != 0) {
                i++;
                continue;
            }

            int start = i;

            while(i <= upper && hash[i] == 0) {
                i++;
            }

            ans.push_back({start, i - 1});
        }
        return ans;
    }
};