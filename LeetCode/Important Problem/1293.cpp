/*
Problem Link - https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[4] = {0, +1, 0, -1};
        int delCol[4] = {+1, 0, -1, 0};

        vector<vector<vector<int>>> dist(
            n,
            vector<vector<int>>(m, vector<int>(k + 1, INT_MAX))
        );

        queue<
            pair<int, pair<int, pair<int, int>>>
        >pq;

        pq.push({0, {k, {0, 0}}});
        dist[0][0][k] = 0;

        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();

            int distance = it.first;
            int remToRemove = it.second.first;
            int row = it.second.second.first;
            int col = it.second.second.second;

            if(remToRemove < 0){
                continue;
            }
            if(row == n-1 && col == m-1){
                return distance;
            }

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int newDist = distance + 1;
                    if(grid[newRow][newCol] == 1){
                        if(remToRemove > 0 &&
                            dist[newRow][newCol][remToRemove-1] > newDist){

                            dist[newRow][newCol][remToRemove-1] = newDist;
                            pq.push({newDist,{remToRemove-1,{newRow,newCol}}});
                        }
                    }
                    else{
                        if(dist[newRow][newCol][remToRemove] > newDist){

                            dist[newRow][newCol][remToRemove] = newDist;
                            pq.push({newDist,{remToRemove,{newRow,newCol}}});
                        }
                    }
                }
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i <= k; i++){
            mini = min(mini, dist[n-1][m-1][i]);
        }
        if(mini == INT_MAX){
            return -1;
        }
        return mini;
    }
};