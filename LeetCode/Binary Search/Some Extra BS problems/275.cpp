#include<bits/stdc++.h>
using namespace std;

//--------------O(nlog(M))-----------

class Solution {
public: 
    bool isPossible(vector<int>& nums, int k, int mid){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= mid){
                count++;
            }
            if(count >= k) return true;
        }
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        int low = 0;
        int high = *max_element(citations.begin(), citations.end());
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(citations, mid, mid)){
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

//-----------O(log(n))--------

int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        int low = 0;
        int high = n-1;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(citations[mid] >= n-mid){
                ans = n - mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }