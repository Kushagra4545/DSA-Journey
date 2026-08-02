/*
Problem Link - https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/description/


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
    
        int count = 0;
        double checkVal = static_cast<double>(a)/b;

        int evenVal = 0;
        int oddVal = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(nums[j] % 2 == 0){
                    evenVal += 1;
                } 
                else{
                    oddVal += 1;
                }

                double val = static_cast<double>(evenVal)/oddVal;

                if(oddVal > 0 && val <= checkVal){
                    count++;
                }
            }
            evenVal = 0;
            oddVal = 0;
        }
        return count;
    }
};