/*
Problem Link = https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isExit(vector<vector<char>>& maze, int row, int col){
        int n = maze.size();
        int m = maze[0].size();

        char ch = maze[row][col];

        if(ch == '.'){
            if((row == 0 || row == n-1) || (col == 0 || col == m-1)){
                return true;
            }
        }
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>>visited(n, vector<int>(m, 0));

        int delRow[4] = {0, +1, 0, -1};
        int delCol[4] = {+1, 0, -1, 0};

        queue<pair<int, pair<int, int>>>q;

        q.push({0, {entrance[0], entrance[1]}});
        visited[entrance[0]][entrance[1]] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row != entrance[0] || col != entrance[1]){
                if(isExit(maze, row, col)){
                    return dist;
                }
            }

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol]){
                    if(maze[newRow][newCol] != '+'){
                        q.push({dist + 1, {newRow, newCol}});
                        visited[newRow][newCol] = 1;
                    }
                }
            }
        }
        return -1;
    }
};