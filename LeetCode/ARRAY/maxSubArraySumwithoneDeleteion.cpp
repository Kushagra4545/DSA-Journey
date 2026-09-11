#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        
        int noDelete = nums[0];
        int oneDelete = INT_MIN;
        int res = INT_MIN;

        for(int i = 1; i < n; i++){
            int prevOnedelete = oneDelete;
            int prevNoDelete = noDelete;

            noDelete = max(noDelete + nums[i], nums[i]);
            int v2;
            if(prevOnedelete == INT_MIN){
                v2 = nums[i];
            }
            else{
                v2 = prevOnedelete + nums[i];
            }
            oneDelete = max(prevNoDelete, v2);

            res = max({res,noDelete, oneDelete});
        }
        return res;
    }
};