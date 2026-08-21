#include<bits/stdc++.h>
using namespace std;

//Time - O(min(log(n), log(m)));
//Space - O(1);

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        if(n1 > n2){
            return kthElement(b, a, k);
        }
        int left = k-1;
        int low = max(0, left - n2);
        int high = min(left, n1);
        
        while(low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1];
            
            if(l1 <= r2 && l2 <= r1){
                return min(r2, r1);
            }
            
            else if(l1 > r2) high = mid1 - 1;
            
            else{
                low = mid1 + 1;
            }
        }
        return 0;
    }
};