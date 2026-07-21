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

int getWhiteSpots(vector<vector<int>>& lights, int n, int m){

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

    cout<<getWhiteSpots(lights, n, m);
}