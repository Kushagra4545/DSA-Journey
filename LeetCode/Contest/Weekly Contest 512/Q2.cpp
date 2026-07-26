/*
Problem Link = https://leetcode.com/contest/weekly-contest-512/problems/aggregate-two-time-series/description/

Time - O(m + n);
Space = O(n + m);

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& series1, vector<vector<int>>& series2, set<vector<int>>& ans){
        int i = 0;
        while (i < series1.size()) {
            int timeStamp1 = series1[i][0];
            int val1 = series1[i][1];
            
            int j = 0;
            bool isFound = false;
            while(j < series2.size()){
                int timeStamp2 = series2[j][0];
                int val2 = series2[j][1];

                if(timeStamp2 >= timeStamp1){
                    ans.insert({timeStamp1, val1 + val2});
                    isFound = true;
                    break;
                }
                j++;
            }
            if(!isFound){
                ans.insert({series1[i][0], series1[i][1]});
            }
            i++;
        }
    }
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;

        int i = 0, j = 0;
        int n = series1.size(), m = series2.size();

        while (i < n || j < m) {

            if (j == m || (i < n && series1[i][0] < series2[j][0])) {

                int t = series1[i][0];
                int sum = series1[i][1] + (j < m ? series2[j][1] : 0);

                ans.push_back({t, sum});
                i++;
            }
            else if (i == n || series2[j][0] < series1[i][0]) {

                int t = series2[j][0];
                int sum = (i < n ? series1[i][1] : 0) + series2[j][1];

                ans.push_back({t, sum});
                j++;
            }
            else {
                int t = series1[i][0];
                int sum = series1[i][1] + series2[j][1];

                ans.push_back({t, sum});
                i++;
                j++;
            }
        }

        return ans;
    }
};