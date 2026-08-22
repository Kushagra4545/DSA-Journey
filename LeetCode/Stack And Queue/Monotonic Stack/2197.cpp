#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int lcm(int a, int b){
        int g = gcd(a, b);
        return (a/g)*b;
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int>st;
        for(int i = 0; i < nums.size(); i++){
            if(st.empty()){
                st.push(nums[i]);
                continue;
            }
            if(gcd(st.top(), nums[i]) != 1){
                int val = nums[i];
                while(!st.empty() && gcd(st.top(), val) != 1){
                    val = lcm(val, st.top());
                    st.pop();
                }
                st.push(val);
            }
            else{
                st.push(nums[i]);
            }
        }
        vector<int>res;
        while(!st.empty()){
            int val = st.top();
            st.pop();
            res.push_back(val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};