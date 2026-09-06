#include<bits/stdc++.h>
using namespace std;

bool isPossible(string s, int i, int j){
    for(int k = i; k <= j; k++){
        if(s[k] == '0'){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        string s;
        cin>>s;

        int count = 0;
        
        int i = 0;
        int j = k-1;

        while(j < n){
            if(!isPossible(s, i, j)){
                count++;
            }
            i = j + 1;
            j = k + j;
        }
        cout<<count<<endl;
    }
}