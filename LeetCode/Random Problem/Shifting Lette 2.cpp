/*
Problem Link - https://leetcode.com/problems/shifting-letters-ii/description/

Time - O(n);
Space - O(n);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts){
        vector<int>hash(s.size() + 1, 0);
        vector<char>ch;

        for(int i = 0; i < 26; i++){
            ch.push_back(static_cast<char>('a' + i));
        }
        cout<<ch[5]<<" "<<ch[6];
        for(int i = 0; i < shifts.size(); i++){
            int start = shifts[i][0];
            int last = shifts[i][1];
            int direction = shifts[i][2];

            if(direction == 1){
                hash[start] += 1;
                hash[last+1] -= 1;
            }
            else{
                hash[start] += -1;
                hash[last+1] += 1;
            }
        }

        int sum = 0;
        for(int i = 0; i < hash.size(); i++){
            sum += hash[i];
            hash[i] = sum;
        }
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            int idx = (26 + hash[i] + (s[i] - 'a')) % 26;
            if(idx < 0) {
                idx += 26;
            }
            ans.push_back(ch[idx]);
        }
        return ans;
    }
};