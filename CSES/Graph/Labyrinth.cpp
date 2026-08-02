#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<string>grid(n);

    for(int i = 0; i < n; i++) {
        cin>>grid[i];
    }

    queue<pair<char, pair<int, int>>>q;

    vector<vector<int>>visited(n, vector<int>(m, 0));

    int delRow[4] = {0, +1, 0, -1};
    int delCol[4] = {+1, 0, -1, 0};
    char direction[4] = {'R', 'D', 'L', 'U'};

    vector<vector<char>>papa(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                q.push({'\0', {i, j}});
                visited[i][j] = 1;
                papa[i][j] = '\0';
            }
        }
    }

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int row = it.second.first;
        int col = it.second.second;

        char parent = it.first;


        if(grid[row][col] == 'B'){
            break;
        }

        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] != '#'){
                q.push({parent, {newRow, newCol}});
                visited[newRow][newCol] = 1;
            }
        }
    }

    
}