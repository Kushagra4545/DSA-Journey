#include<bits/stdc++.h>
using namespace std;

//--------- O(N + M)---------- 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        int n1,n2;
        int i = 0;
        int j = 0;
        int count = 0;

        while(i < nums1.size() && j < nums2.size()){
            int val;
            if(nums1[i] <= nums2[j]){
                val = nums1[i];
                i++;
            }
            else{
                val = nums2[j];
                j++;
            }

            count++;

            if(count == n/2){
                n1 = val;
            }
            if(count == n/2 + 1){
                n2 = val;
                break;
            }
        }

        while(i < nums1.size() && count < n/2 + 1){
            count++;
            if(count == n/2){
                n1 = nums1[i];
            }
            if(count == n/2 + 1){
                n2 = nums1[i];
                break;
            }
            i++;
        }

        while(j < nums2.size() && count < n/2 + 1){
            count++;
            if(count == n/2){
                n1 = nums2[j];
            }
            if(count == n/2 + 1){
                n2 = nums2[j];
                break;
            }
            j++;
        }

        if(n % 2 == 0){
            return (n1 + n2)/2.0;
        }
        return n2;
    }
};

//---------O(min(logn, logm));
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = min(nums1.size(), nums2.size());
        int left = (n1 + n2 + 1)/2;

        while(low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1-1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){
                int n = n1 + n2;
                if(n % 2 == 0){
                    double val = (double)(max(l1, l2) + min(r1, r2))/2.0;
                    return val;
                }
                else{
                    return max(l1, l2);
                }
            }

            else if(l1 > r2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }
        }
        return 0;
    }
};