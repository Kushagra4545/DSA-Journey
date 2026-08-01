/*
Problem Link = https://leetcode.com/problems/minimum-initial-strength-to-defeat-all-monsters/description/

Time 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(long long val, vector<int>& monsters, vector<long long>& bonus){
        for(int i = 0; i < monsters.size(); i++){
            if(bonus[i] + val < monsters[i]){
                return false;
            }
            val = max(0*1LL, val - monsters[i]);
        }
        if(val < 0) return false;
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        vector<long long>bonus(monsters.size() + 1, 0);
        
        for(int i = 0; i < boosts.size(); i++){
            int left = boosts[i][0];
            int right = boosts[i][1];
            int val = boosts[i][2];

            bonus[left] += val;
            bonus[right + 1] += -1*val;
        }
        long long sum = 0;
        for(int i = 0; i < bonus.size(); i++){
            sum += bonus[i];
            bonus[i] = sum;
        }

        long long totalMonsterSumm = 0;
        for(int i =0; i < monsters.size(); i++){
            totalMonsterSumm += monsters[i];
        }

        long long low = 0;
        long long high = totalMonsterSumm;
        long long ans = LLONG_MAX;
        
        while(low <= high){
            long long mid = low + (high - low)/2;

            if(isSafe(mid, monsters, bonus)){
                ans = min(ans, mid);
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};