/*
Problem Link = https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

Time - O(nm log(nm));
Space - O(nm);
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[4] = {0, +1, 0, -1};
        int delCol[4] = {+1, 0, -1, 0};

        vector<vector<int>>obstacle(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        >pq;

        if(grid[0][0] == 1){
            pq.push({1, {0, 0}});
            obstacle[0][0] = 1;
        }
        else{
            pq.push({0, {0, 0}});
            obstacle[0][0] = 0;
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int minObst = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1) {
                return minObst;
            }

            for(int i = 0; i < 4; i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int obstacleTorem = minObst;
                    if(grid[newRow][newCol] == 1){
                        obstacleTorem++;
                    }
                    if(obstacleTorem < obstacle[newRow][newCol]){
                        obstacle[newRow][newCol] = obstacleTorem;
                        pq.push({obstacleTorem, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};