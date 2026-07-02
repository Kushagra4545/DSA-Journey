/* 
Problem Link - https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/

Time - O(N*n log(n));
Space - O(n*n);
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        int delRow[4] = {-1, 0, 1, 0};
        int delCol[4] = {0, 1, 0, -1};

        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));

        queue<pair<int, int>>q;

        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int r = it.first;
            int c = it.second;

            for(int i = 0; i < 4; i++){
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && dist[newRow][newCol] == INT_MAX){
                    dist[newRow][newCol] = dist[r][c] + 1;
                    q.push({newRow, newCol});
                }
            }
        }

        vector<vector<int>>best(n, vector<int>(n, -1));

        priority_queue<
            pair<int, pair<int, int>>
        >pq;

        pq.push({dist[0][0], {0, 0}});
        best[0][0] = dist[0][0];

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int safeDist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == n-1){
                return safeDist;
            }

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n){
                    int newSafeDist = min(safeDist, dist[newRow][newCol]);

                    if(newSafeDist > best[newRow][newCol]){
                        best[newRow][newCol] = newSafeDist;
                        pq.push({newSafeDist, {newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
};