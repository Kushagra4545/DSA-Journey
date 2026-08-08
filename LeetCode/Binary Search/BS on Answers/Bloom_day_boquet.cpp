#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<int>& bloomDay, int m, int k, int mid){
        int n = bloomDay.size(); 

        int count = 0;
        int maxGroups = 0;

        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= mid){
                count++;
            }
            else{
                count = 0;
            }
            if(count == k){
                maxGroups += 1;
                count = 0;
            }
        }

        if(maxGroups >= m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isSafe(bloomDay, m, k, mid)){
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