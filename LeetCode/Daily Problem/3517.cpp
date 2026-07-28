/*
Problem Link - https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/

Time - O(n*n);
Space - O(n);
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>mpp;

        for(auto it : s){
            mpp[it]++;
        }

        string ans = "";

        char ch = '\0';

        for(auto it : mpp){
            int count = it.second;
            if(count % 2 != 0){
                ch = it.first;
            }
            for(int i = 0; i < count/2; i++){
                ans.push_back(it.first);
            }
        }

        string rev = ans;
        reverse(rev.begin(), rev.end());
        if(ch != '\0'){
            ans.push_back(ch);
        }
        return ans + rev;
    }
};