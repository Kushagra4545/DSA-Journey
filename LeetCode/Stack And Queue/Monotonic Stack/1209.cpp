#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;

        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push({s[i], 1});
                continue;
            }
            char ch = st.top().first;
            int count = st.top().second;

            if(ch == s[i]){
                int newCount = count + 1;
                if(newCount == k){
                    for(int j = 1; j <= k-1; j++){
                        st.pop();
                    }
                }
                else{
                    st.push({s[i], newCount});
                }
            }
            else{
                st.push({s[i], 1});
            }
        }
        string res;
        while(!st.empty()){
            char ch = st.top().first;
            st.pop();
            res.push_back(ch);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};