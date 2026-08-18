#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isPossible(vector<int>& arr, int k, int mid){
        int count = 1;
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++){
            if(sum + arr[i] <= mid){
                sum += arr[i];
            }
            else{
                count++;
                sum = arr[i];
            }
        }
        if(count <= k){
            return true;
        }
        return false;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isPossible(arr, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};