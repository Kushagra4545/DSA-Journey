/*
Problem Link - https://www.geeksforgeeks.org/problems/implement-upper-bound/1

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int upperBound = arr.size();
        
        int low = 0;
        int high = n-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(target < arr[mid]){
                upperBound = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return upperBound;
    }
};
