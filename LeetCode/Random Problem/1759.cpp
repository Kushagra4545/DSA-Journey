#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/count-number-of-homogenous-substrings/
*/

class Solution {
public:
    int mod = 1e9 + 7;
    long long numberOfCount(int n){
        return (1LL*n*(n+1))/2;
    }
    int countHomogenous(string s) {
        int count = 0;
        int i = 0;
        int j = 0;

        while(j < s.size()){
            if(s[i] != s[j]){
                count = (count + numberOfCount(j-i)) % mod;
                i = j;
                continue;
            }
            else{
                j++;
            }
        }

        count += numberOfCount(j-i) % mod;
        return count % mod;
    }
};