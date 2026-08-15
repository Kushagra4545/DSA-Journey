#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<string>& grid, vector<vector<int>>& visited, int delRow[], int delCol[]){
    int n = grid.size();
    int m = grid[0].size();

    visited[row][col] = 1;

    for(int i = 0; i < 4; i++){
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] == '.'){
            dfs(newRow, newCol, grid, visited, delRow, delCol);
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

    int delRow[4] = {0, +1, 0, -1};
    int delCol[4] = {+1, 0, -1, 0};

    vector<vector<int>>visited(n, vector<int>(m, 0));

    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                dfs(i, j, grid, visited, delRow, delCol);
                count++;
            }
        }
    }
    cout<<count;
}