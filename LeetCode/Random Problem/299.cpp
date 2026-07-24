/*
Problem Link : https://leetcode.com/problems/bulls-and-cows/

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        map<char, int>mpp3;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                bulls++;
                mpp3[secret[i]]++;
            }
        }

        map<char, int>mpp1;
        map<char, int>mpp2;

        for(auto it : secret){
            mpp1[it]++;
        }
        for(auto it : guess){
            mpp2[it]++;
        }

        int cows = 0;

        for(auto it : mpp2){
            int freq1 = it.second;
            char ch = it.first;

            if(mpp1.find(ch) != mpp1.end()){
                int freq2 = mpp1[ch];
                int common = min(freq1, freq2);
                
                if(mpp3.find(ch) != mpp3.end()){
                    int freq3 = mpp3[ch];
                    cows += (common - freq3);
                }
                else{
                    cows += common;
                }
            }
            else {
                continue;
            }
        }
        
        //string a = "";
        string b = to_string(bulls);
        string c = to_string(cows);
        return b + "A" + c + "B";
    }
};