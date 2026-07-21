/*
-------Problem Statement-------

You are given security values of 26 length Where each letter corresponds 
to there index as there security value. there is also a security message 
the neighbours security values are substracted and sum up all these 
find the min of the sum.

*/

#include<bits/stdc++.h>
using namespace std;

int getMin(vector<int>& security_values, string msg){
    
}

int main(){
    vector<int>security_values;
    for(int i = 1; i <= 26; i++){
        security_values.push_back(i);
    }

    string msg = "afeb";

    cout<<getMin(security_values, msg);
}