#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int c, vector<vector<int>>& adjList, vector<int>& color){
    color[node] = c;

    for(auto it : adjList[node]){
        if(color[it] == -1){
            bool val = dfs(it, !c, adjList, color);
            if(val == false) return false;
        }
        else if(color[it] == c){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<vector<int>>adjList(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int>color(n+1, -1);

    bool flag = true;

    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            bool val = dfs(i, 1, adjList, color);
            if(val == false){
                flag = false;
                break;
            }
        }
    }

    if(flag == false){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            color[i] = 2;
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<color[i]<<" ";
    }
}