#include<bits/stdc++.h>
using namespace std;

//----------O(log(n) * log(m))--------

class Solution {
public:
    bool isPresent(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(target < nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][m-1]){
                if(isPresent(matrix[mid], target)) return true;
                return false;
            }
            else if(target < matrix[mid][0]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};