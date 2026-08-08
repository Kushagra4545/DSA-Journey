#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<int>& piles, int h, int mid){
        int count = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] % mid == 0){
                count += piles[i]/mid;
            }
            else{
                count += piles[i]/mid + 1;
            }
            if(count > h) return false;
        }
        if(count > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isSafe(piles, h, mid)){
                ans = min(mid, ans);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};