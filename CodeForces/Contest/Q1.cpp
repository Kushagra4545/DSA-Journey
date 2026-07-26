#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> w(n);

        for (int i = 0; i < n; i++)
            cin >> w[i];

        if(n % 2 != 0){
            cout<<"NO"<<endl;
            continue;
        }

        int minEven = w[1];
        int minOdd = w[0];

        for(int i = 0; i < n; i++){
            if(i % 2 != 0){
                minEven = max(minEven, w[i]);
            }
            else{
                minOdd = min(minOdd, w[i]);
            }
        }

        if(minOdd - minEven >= 2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}