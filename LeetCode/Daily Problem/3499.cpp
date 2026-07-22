/*
problem Link - https://leetcode.com/problems/maximize-active-section-with-trade-i/description/

Time - O(n);
Space - O(1); 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(string s){
        int i = 0;
        int j = s.size()-1;

        while(i < j){
            if(s[i] == '1' && s[j] == '1'){
                i++;
                j--;
            }
            else if(s[i] == '1' && s[j] == '0'){
                i++;
            }
            else if(s[i] == '0' && s[j] == '1'){
                j--;
            }
            else{
                break;
            }
        }
        bool flag = false;
        for(int k = i; k <= j; k++){
            if(s[k] == '1'){
                flag = true;
                break;
            }
        }
        if(abs(i-j) < 2 || flag == false){
            return false;
        }
        return true;
    }
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int maxCount = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        int i = 0;
        while(i < n){
            while(s[i] == '0'){
                count1++;
                i++;
            }
            while(s[i] == '1'){
                i++;
            }
            while(s[i] == '0'){
                count2++;
                i++;
            }

            maxCount = max(maxCount, count1 + count2);
            count1 = count2;
            count2 = 0;
        }
 
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') count++;
        }
        if(n <= 2 || count == 0 || check(s) == false){
            return count;
        }
        return maxCount + count;
    }
};