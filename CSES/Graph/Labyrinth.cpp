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

    vector<vector<int>>visited(n, vector<int>(m, 0));

    int delRow[4] = {0, +1, 0, -1};
    int delCol[4] = {+1, 0, -1, 0};
    char dir[4] = {'R', 'D', 'L', 'U'};

    vector<vector<pair<int, int>>>parent(n, vector<pair<int, int>>(m, {-1, -1}));
    
    vector<vector<char>>move(n, vector<char>(m));

    int stRow, stCol;
    int endRow, endCol;

    for(int i = 0; i < n; i++){
        for(int j =0; j < m; j++){
            if(grid[i][j] == 'A'){
                stRow = i;
                stCol = j;
            }
            if(grid[i][j] == 'B'){
                endRow = i;
                endCol = j;
            }
        }
    }

    queue<pair<int, int>>q;
    q.push({stRow, stCol});
    visited[stRow][stCol] = 1;

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int row = it.first;
        int col = it.second;

        if(row == endRow && col == endCol){
            break;
        }

        for(int i = 0; i < 4; i++){
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] != '#' && !visited[newRow][newCol]){
                visited[newRow][newCol] = 1;
                parent[newRow][newCol] = {row, col};
                move[newRow][newCol] = dir[i];

                q.push({newRow, newCol});
            }
        }
    }

    if(visited[endRow][endCol] == 0){
        cout<<"NO"<<endl;
        return 0;
    }
    string path;

    int r = endRow;
    int c = endCol;

    while(r != stRow || c != stCol){
        path.push_back(move[r][c]);

        auto it = parent[r][c];

        r = it.first;
        c = it.second;
    }

    reverse(path.begin(), path.end());

    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;
}