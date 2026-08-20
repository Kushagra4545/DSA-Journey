#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int isPossible(vector<int>& diff, int k, double mid){
        int count = 0;
        for(int i = 0; i < diff.size(); i++){
            count += ceil(diff[i]/mid) - 1;
        }
        return count;
    }
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        if(stations.size() == 1) return 0.0;
        vector<int>diff;
        for(int i = 1; i < stations.size(); i++){
            diff.push_back(stations[i] - stations[i-1]);
        }
        
        double low = 0;
        double high = *max_element(diff.begin(), diff.end());
        double d = 1e-6;
        while(high - low > d){
            double mid = low + (high - low)/2.0;
            int count = isPossible(diff, k, mid);
            if(count > k) low = mid;
            else{
                high = mid;
            }
            
        }
        return high;
    }
};