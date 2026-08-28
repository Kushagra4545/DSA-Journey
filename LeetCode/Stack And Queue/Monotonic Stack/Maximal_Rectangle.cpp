#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmaller(vector<int>& nums){
        int n = nums.size();

        vector<int>res(n);
        stack<int>st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = n;
            }
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> prevSmaller(vector<int>& nums){
        int n = nums.size();

        vector<int>res(n);
        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }
            else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    int maxArea(vector<int>& nums){
        int n = nums.size();

        vector<int>prevSmall = prevSmaller(nums);
        vector<int>nextSmall = nextSmaller(nums);

        int area = 0;

        for(int i = 0; i < n; i++){
            int left = prevSmall[i] + 1;
            int right = nextSmall[i] - 1;

            int a = nums[i] * (right - left + 1);

            area = max(area, a);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int area = 0;
        vector<int>nums(m, 0);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    nums[j] += 1;
                }
                else{
                    nums[j] = 0;
                }
            }
            int a = maxArea(nums);
            area = max(area, a);
        }
        return area;
    }
};