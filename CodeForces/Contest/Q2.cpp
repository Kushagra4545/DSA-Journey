#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;

        if(k >= n || (n > 1 && k == n - 1)){
            cout<<-1<<endl;
            continue;
        }

        int count0 = (n + 1) / 2;
        int count1 = n / 2;
        int totalBlocks = n - k;
        int blocks0 = (totalBlocks + 1) / 2;
        int blocks1 = totalBlocks / 2;

        int extra0 = count0 - blocks0;
        int extra1 = count1 - blocks1;

        string resultString;
        resultString.reserve(n);

        int currentChar = 0;
        for (int i = 0; i < totalBlocks; ++i) {
            if (currentChar == 0) {
                int blockSize = 1 + extra0;
                extra0 = 0; 
                resultString.append(blockSize, '0');
                currentChar = 1;
            } else {
                int blockSize = 1 + extra1;
                extra1 = 0; 
                resultString.append(blockSize, '1');
                currentChar = 0;
            }
        }
        cout<<resultString<<endl;
    }
}