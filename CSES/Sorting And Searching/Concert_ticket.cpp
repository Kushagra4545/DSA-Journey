#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int>price(n);

    for(int i = 0; i < n; i++){
        cin>>price[i];
    }

    vector<int>maxPrice(m);

    for(int i = 0; i < m; i++){
        cin>>maxPrice[i];
    }

    sort(price.begin(), price.end());

    for(int i = 0; i < min(n, m); i++){
        if(maxPrice[i] >= price[i]){
            cout<<maxPrice[i]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }

    if(n < m){
        for(int i = 1; i < m-n; i++){
            cout<<-1<<endl;
        }
    }
}