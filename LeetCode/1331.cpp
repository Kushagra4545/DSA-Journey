/*
Problem Link - https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2026-07-12

Time - O(nlogn);
SPace - O(2n) = O(n);

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) return {};
        vector<int>temp = arr;
        sort(temp.begin(), temp.end());
        
        unordered_map<int, int>mpp;
        mpp[temp[0]] = 1;
        int count = 2;
        for(int i = 1; i < temp.size(); i++){
            if(temp[i-1] != temp[i]){
                mpp[temp[i]] = count++;
            }
        }

        vector<int>ans;
        for(int i = 0; i < arr.size(); i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};
