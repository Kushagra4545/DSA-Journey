#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<int>& weights, int days, int mid){
        int count = 1;
        int sum = 0;

        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] > mid){
                count++;
                sum = weights[i];
            }
            else{
                sum += weights[i];
            }
        }
        if(count <= days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;

        for(int i = 0; i < weights.size(); i++){
            high += weights[i];
        }

        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isSafe(weights, days, mid)){
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