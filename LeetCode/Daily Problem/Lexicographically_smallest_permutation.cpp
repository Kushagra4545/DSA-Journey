#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
*/
class Solution {
public:
    bool helper(int idx, string &res, string target, vector<int>& hash){
        int n = target.size();

        if(idx == n){
            return res > target;
        }

        int x = target[idx] - 'a';

        if(hash[x] > 0){
            res.push_back(target[idx]);
            hash[x]--;

            if(helper(idx + 1, res, target, hash)){
                return true;
            }

            res.pop_back();
            hash[x]++;
        }

        for(int i = x + 1; i < 26; i++){
            if(hash[i] > 0){
                res.push_back('a' + i);
                hash[i]--;

                for(int j = 0; j < 26; j++){
                    while(hash[j] > 0){
                        res.push_back(j + 'a');
                        hash[j]--;
                    }
                }
                return true;
            }
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int>hash(26, 0);
        
        for(auto it : s){
            hash[it - 'a']++;
        }
        string res = "";

        if(helper(0, res, target, hash)){
            return res;
        }
        return "";
    }
};
