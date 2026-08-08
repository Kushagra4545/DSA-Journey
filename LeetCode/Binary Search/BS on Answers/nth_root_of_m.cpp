#include<bits/stdc++.h>
using namespace std;

    int mul(int n, int mid, int m){
        int multi = 1;
        
        for(int i = 0; i < n; i++){
            multi *= mid;
            if(multi > m) break;
        }
        return multi;
    }
    int nthRoot(int n, int m) {
        // Code here
        if(m == 0) return 0;
        int low = 1;
        int high = m;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            int val = mul(n, mid, m);
            if(val == m){
                return mid;
            }
            if(val < m){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }