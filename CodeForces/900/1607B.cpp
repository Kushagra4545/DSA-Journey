#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x;
        cin>>x;
        long long n;
        cin>>n;
        
        long long final;
        if(n % 4 == 0){
            final = 0;
        }
        else if(n % 4 == 1){
            final = -n;
        }
        else if(n % 4 == 2){
            final = 1;
        }
        else if(n % 4 == 3) {
            final = n + 1;
        }
        
        if(x % 2 == 0){
            cout<<x + final<<endl;
        }
        else{
            cout<<x - final<<endl;
        }

    }
}