#include<bits/stdc++.h>
using namespace std;

int delRow[4] = {0, +1, 0, -1};
int delCol[4] = {+1, 0, -1, 0};

void dfs(int row, int col, vector<string>& grid, vector<vector<int>>& visited, int n, int m){

    visited[row][col] = 1;

    for(int i =0; i < 4; i++){
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol]){
            if(grid[newRow][newCol] == '.'){
                dfs(newRow, newCol, grid, visited, n, m);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<string>grid(n);

    for(int i = 0; i < n; i++){
        cin>>grid[i];
    }

    vector<vector<int>>visited(n, vector<int>(m, 0));

    int count = 0;

    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                dfs(i, j, grid, visited, n, m);
                count++;
            }
        }
    }

    cout<<count;
}