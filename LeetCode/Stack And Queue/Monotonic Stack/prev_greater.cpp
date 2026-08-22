#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<int>res;
        stack<int>st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                res.push_back(-1);
                st.push(arr[i]);
                continue;
            }
            if(st.top() > arr[i]){
                res.push_back(st.top());
            }
            else{
                while(!st.empty() && st.top() <= arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    res.push_back(-1);
                }
                else{
                    res.push_back(st.top());
                }
            }
            st.push(arr[i]);
        }
        return res;
    }
};