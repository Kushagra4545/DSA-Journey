/*
Problem Link : https://leetcode.com/problems/sequential-digits/description/

Time = O(1);
Space = O(1);
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool funct(int n){
        int prev = n % 10;
        n = n/10;
        while(n > 0){
            int ld = n % 10;
            if(ld >= prev || abs(ld - prev) > 1){
                return false;
            }
            prev = ld;
            n = n/10;
        }
        return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s = "123456789";

        for(int length = 2; length <= 9; length++){
            for(int i = 0; i + length <= 9; i++){
                int n = stoi(s.substr(i, length));

                if(n <= high && n >= low){
                    ans.push_back(n);
                }
            }
        }
        return ans;
    }
};