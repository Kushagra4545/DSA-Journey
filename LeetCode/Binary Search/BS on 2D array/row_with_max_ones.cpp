#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countOnes(vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
        int idx = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == 1){
                high = mid - 1;
            }
            else{
                idx = mid;
                low = mid + 1;
            }
        }
        if(idx == -1) return nums.size();
        return nums.size()-1-idx;
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int count = 0;
        int idx = -1;
        
        for(int i = 0; i < arr.size(); i++){
            int val = countOnes(arr[i]);
            if(val > count){
                idx = i;
                count = max(count, val);
            }
        }
        return idx;
    }
};