#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int leftElems = nums[mid] - mid -1;
            if(leftElems < k){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return k + high + 1;
    }
};