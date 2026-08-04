/*
Problem Link - https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target){
        int n = arr.size();
        int ans = 0;
        
        int low = 0;
        int high = n -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(target >= arr[mid]){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(ans != -1){
            if(arr[ans] != target) return -1;
        }
        return ans;
    }
    int upperBound(vector<int>& arr, int target){
        int n = arr.size();
        
        int ans = 0;
        
        int low = 0;
        int high = n - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        if(ans != -1){
            if(arr[ans] != target){
                return -1;
            }
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        int lb = lowerBound(arr, target);
        int ub = upperBound(arr, target);
        
        if(lb == -1 || ub == -1){
            return 0;
        }
        return abs(ub - lb) + 1;
    }
};
