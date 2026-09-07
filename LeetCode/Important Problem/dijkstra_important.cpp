/*
Problem Link = https://leetcode.com/problems/minimum-cost-path-with-at-most-k-turns/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[4] = {0, +1, 0, -1};
        int delCol[4] = {+1, 0, -1, 0};
        char direction[4] = {'R', 'D', 'L', 'U'};

        vector<vector<vector<vector<int>>>>dist(
            n, 
            vector<vector<vector<int>>>(
                m, 
                vector<vector<int>>(
                    k+1,
                    vector<int>(4, INT_MAX)
                )
            )
        );

        priority_queue<
            pair<int, pair<int, pair<char, pair<int, int>>>>,
            vector<pair<int, pair<int, pair<char, pair<int, int>>>>>,
            greater<pair<int, pair<int, pair<char, pair<int, int>>>>>
        >q;

        q.push({grid[0][0], {k, {'#', {0, 0}}}});
        dist[0][0][k][0] = grid[0][0];
        dist[0][0][k][1] = grid[0][0];
        dist[0][0][k][2] = grid[0][0];
        dist[0][0][k][3] = grid[0][0];

        while(!q.empty()){
            auto it = q.top();
            q.pop();
            
            int remTurns = it.second.first;
            int distance = it.first;
            char prevDir = it.second.second.first;
            int row = it.second.second.second.first;
            int col = it.second.second.second.second;

            if(remTurns < 0){
                continue;
            }

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                char newDir = direction[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int newDist = distance + grid[newRow][newCol];
                    int newRemTurns = remTurns;
                    if(newDir != prevDir && prevDir != '#'){
                        newRemTurns -= 1;
                    }
                    if(newRemTurns < 0){
                        continue;
                    }
                    if(dist[newRow][newCol][newRemTurns][i] > newDist){
                        q.push({newDist, {newRemTurns, {newDir, {newRow, newCol}}}});
                        dist[newRow][newCol][newRemTurns][i] = newDist;
                    }
                }
            }
        }
        
        int minDist = INT_MAX;
        for(int i = 0; i <= k; i++){
            for(int j = 0; j < 4; j++){
                minDist = min(minDist, dist[n-1][m-1][i][j]);
            }
        }
        if(minDist == INT_MAX) return -1;
        return minDist;
    }
};