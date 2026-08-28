#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size();

        stack<char>st;

        for(int i = 0; i < n; i++){
            if(k == 0){
                st.push(nums[i]);
                continue;
            }
            while(!st.empty() && k > 0 && st.top() > nums[i]){
                k--;
                st.pop();
            }
            st.push(nums[i]);
        }

        while(k > 0){
            k--;
            st.pop();
        }

        string ans = "";

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        if(ans.size() == 0){
            return "0";
        }

        int i = ans.size()-1;

        while(i > 0){
            if(ans[i] != '0'){
                break;
            }
            else{
                ans.pop_back();
            }
            i--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};