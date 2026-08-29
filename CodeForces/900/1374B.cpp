#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;

        int count = 0;
        bool flag = false;

        while(n > 1){
            if(n % 2 == 0){
                if(n % 3 == 0){
                    count++;
                    n = n/6;
                }
                else{
                    flag = true;
                    break;
                }
            }
            else{
                count++;
                n = n*2;
            }
        }
        
        if(flag == true){
            cout<<-1<<endl;
        }
        else{
            cout<<count<<endl;
        }
    }
}