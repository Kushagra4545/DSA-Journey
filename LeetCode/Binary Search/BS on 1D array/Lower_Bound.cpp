/*
Problem Link = https://www.geeksforgeeks.org/problems/implement-lower-bound/1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int smallest = arr.size();
        
        int low = 0;
        int high = arr.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] >= target){
                smallest = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return smallest;
    }
};
