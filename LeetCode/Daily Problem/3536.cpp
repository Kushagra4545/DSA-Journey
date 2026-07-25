/*
Problem Link - https://leetcode.com/problems/maximum-product-of-two-digits/description/

Time - O(logn);
Space - O(logn);

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int n){
        vector<int>arr;
        while(n > 0){
            int ld = n % 10;
            arr.push_back(ld);
            n = n/10;
        }
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        return arr[sz-1]*arr[sz-2];
    }
    int maxProduct(int n) {
        string s = to_string(n);

        sort(s.begin(), s.end());

        int sz = s.size();
        int max = (s[sz-1] - '0') * (s[sz-2] - '0');
        return max;
    }
};