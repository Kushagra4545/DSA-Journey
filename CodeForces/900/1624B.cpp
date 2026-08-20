#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;

        int mod1 = (2*b-c) % a;
        int mod2 = (a + c) % (2*b);
        int mod3 = (2*b-a) % c;
        double val1 = (2*b-c) / (double)a;
        double val2 = (a + c) / (double)(2*b);
        double val3 = (2*b-a) / (double)c;

        if((mod1 == 0 && val1 > 0) || (mod2 == 0 && val2 > 0) || (mod3 == 0 && val3 > 0)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}