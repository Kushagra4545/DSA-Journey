/*
-----PROBLEM STATEMENT----

A stage n metres long has m lights installed 
1- red
2 - blue
3 - green

find the number of of white spots.

Red + Green + Blue = White Spot

*/

#include<bits/stdc++.h>
using namespace std;

//My solution
int getWhiteSpotsBrute(vector<vector<int>>& lights, int n, int m){
    vector<int>hash(n+1, 0);
    vector<int>red(n+1, 0);
    vector<int>blue(n+1, 0);
    vector<int>green(n+1, 0);
    
    for(int i = 0; i < lights.size(); i++){
        for(int j = lights[i][1]; j <= lights[i][2]; j++){
            if(lights[i][0] == 1){
                red[j] = 1;
            }
            else if(lights[i][0] == 2){
                blue[j] = 1;
            }
            else{
                green[j] = 1;
            }
            hash[j]++;
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        if(hash[i] >= 3 && red[i] == 1 && blue[i] == 1 && green[i] == 1){
            count++;
        } 
    }
    return count;
}

int main(){
    int n = 10;
    int m = 5;

    vector<vector<int>>lights = {
        {1,2,7},
        {2,3,8},
        {3,4,9},
        {2, 9, 10},
        {3, 5, 7}
    };

    cout<<getWhiteSpotsBrute(lights, n, m);
}