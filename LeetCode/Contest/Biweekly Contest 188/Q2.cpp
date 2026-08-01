/*
Problem Link = https://leetcode.com/problems/count-valid-prefixes/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidPrefixes(string s) {
        int count = 0;
        int countZero = 0;
        int countOne = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0') countZero++;
            else if(s[i] == '1') countOne++;
            if(abs(countZero - countOne) <= 1){
                count++;
            }
        }
        return count;
    }
};