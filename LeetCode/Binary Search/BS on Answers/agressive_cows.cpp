#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPlace(vector<int>& arr, int k, int d){
        int lastPosi = arr[0];
        
        int count = 1;
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - lastPosi >= d){
                count++;
                lastPosi = arr[i];
            }
            
            if(count >= k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int low = 1;
        int high = arr[n-1] - arr[0];
        
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(canPlace(arr, k, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};