#include<bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int>nums;
    vector<int>blocks;
    int n;
    int blockSize;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        blockSize = ceil(sqrt(n));
        blocks.resize(blockSize, 0);

        for(int i = 0; i < n; i++){
            int idx = i/blockSize;
            blocks[idx] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int idx = index/blockSize;
        blocks[idx] -= nums[index];
        blocks[idx] += val;
        nums[index] = val;
    }
     
    int sumRange(int left, int right) {
        int startBlock = left/blockSize;
        int endBlock = right/blockSize;

        //case : 1
        if(startBlock == endBlock){
            int sum = 0;
            for(int i = left; i <= right; i++){
                sum += nums[i];
            }
            return sum;
        }
        //case : 2
        else{
            int sum = 0;
            int endOfstartBlock = ((startBlock + 1)*blockSize) - 1;
            int startIdxofLastBlock = endBlock * blockSize;

            //left
            for(int i = left; i <= endOfstartBlock; i++){
                sum += nums[i];
            }

            //middle
            for(int i = startBlock + 1; i < endBlock; i++){
                sum += blocks[i];
            }

            //right 
            for(int i = startIdxofLastBlock; i <= right; i++){
                sum += nums[i];
            }
            return sum;
        }
        return 0;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */