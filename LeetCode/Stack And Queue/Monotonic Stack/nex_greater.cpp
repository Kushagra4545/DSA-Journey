#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>res;
        stack<int>st;
        
        for(int i = n-1; i >= 0; i--){
            if(st.empty()){
                res.push_back(-1);
            }
            else if(st.top() > arr[i]){
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
        reverse(res.begin(), res.end());
        return res;
    }
};