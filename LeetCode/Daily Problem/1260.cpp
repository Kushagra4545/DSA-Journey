/*
Problem Link = https://leetcode.com/problems/shift-2d-grid/description/

Time - O(m*n);
Space = O(m*n);
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(int stIdx, int endIdx, vector<int>& ans){
        while(stIdx < endIdx){
            swap(ans[stIdx], ans[endIdx]);
            stIdx++;
            endIdx--;
        }
    }
    void rotate(vector<int>& ans, int k){
        int n = ans.size();
        k = k % n;

        reverse(0, n-1, ans);
        reverse(0, k-1, ans);
        reverse(k, n-1, ans);
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>ans;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans.push_back(grid[i][j]);
            }
        }

        rotate(ans, k);

        vector<vector<int>>mat(m, vector<int>(n, 0));

        int p = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = ans[p++];
            }
        }
        return mat;
    }
};