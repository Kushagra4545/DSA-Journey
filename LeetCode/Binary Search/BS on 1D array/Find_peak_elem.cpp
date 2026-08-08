#include<bits/stdc++.h>
using namespace std;
//solution 1 Which i implemented
int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid - 1 >= 0 && mid + 1 < n && nums[mid] > nums[mid-1] && nums[mid] > nums[mid + 1]){
                return mid;
            }
            //increasing 
            if(mid - 1 >= 0 && nums[mid - 1] <= nums[mid]){
                if(nums[mid] >= nums[low]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            else if(mid + 1 < n){
                if(nums[mid] >= nums[high]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return -1;
    }

    //Optimal Logic 

    int optimal(vector<int>& nums){
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid + 1] > nums[mid]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }