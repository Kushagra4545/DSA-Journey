/*
Problem Link = https://leetcode.com/problems/maximum-number-of-points-with-cost/description/


*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Time = O(n*m*m);
    //Space = O(n*n) + O(n) -> stack Space
    long long helper(int row, int col, vector<vector<int>>& points, vector<vector<int>>& dp){
        int n = points.size();
        int m = points[0].size();

        if(row == n-1){
            return points[row][col];
        }
        if(row >= n){
            return 0;
        }
        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }
        int maxi = INT_MIN;

        for(int i = 0; i < m; i++){
            int p = points[row][col] - abs(col - i) + helper(row+1, i, points, dp); 
            maxi = max(p, maxi);
        }
        return dp[row][col] = maxi;
    }
    //Time = O(n*m);
    //Space = O(n*n);
    long long helperTab(vector<vector<int>>& points){
        int n = points.size();
        int m = points[0].size();

        vector<vector<long long>>dp(n, vector<long long>(m , 0));

        for(int i = 0; i < m; i++){
            dp[n-1][i] = points[n-1][i];
        }

        long long prevMax = INT_MIN;
        int prevCol = 0;

        for(int i = n-2; i >= 0; i--){
            vector<long long>left(m), right(m);

            left[0] = dp[i+1][0];

            //left = max(dp[i+1][k] - k)

            for(int j = 1; j < m; j++){
                left[j] = max(left[j-1], dp[i+1][j] + j);
            }

            //right = max(dp[i+1][k] - k)

            right[m-1] = dp[i+1][m-1] - (m-1);
            for(int j = m-2; j >= 0; j--){
                right[j] = max(right[j+1], dp[i+1][j] - j);
            }

            for(int j = 0; j < m; j++){
                long long maxi = max({left[j] - j, right[j] + j});
                dp[i][j] = maxi + points[i][j];
            }
        }

        long long maxi = INT_MIN;
        for(int i = 0; i < m; i++){
            maxi = max(maxi, dp[0][i]);
        }
        return maxi;
    }
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();

        vector<vector<int>>dp(n, vector<int>(m, INT_MAX));

        // long long maxi = helper(0, 0, points, dp);

        // for(int i = 0; i < m; i++){
        //     long long val = helper(0, i, points, dp);
        //     maxi = max(maxi, val);
        // }
        // return maxi;

        return helperTab(points);
    }
};