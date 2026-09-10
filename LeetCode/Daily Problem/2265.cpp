#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  
class Solution {
public:
    pair<int, int> sumAndCount(TreeNode* root){
        if(root == NULL) return {0, 0};

        int leftSum = 0;
        int rightSum = 0;
        int leftCount = 0;
        int rightCount = 0;

        auto l = sumAndCount(root->left);
        auto r = sumAndCount(root->right);

        if(root->left != NULL){
            leftCount = l.first;
            leftSum = l.second;
        }
        if(root->right != NULL){
            rightCount = r.first;
            rightSum = r.second;
        }

        int totalSum = leftSum + rightSum + root->val;
        int totalCount = 1 + leftCount + rightCount;

        return {totalCount, totalSum};
    }
    tuple<int, int, int> count(TreeNode* root){
        if(!root) return {0, 0, 0};

        auto [leftSum, leftCount, leftAns] = count(root->left);
        auto [rightSum, rightCount, rightAns] = count(root->right);

        int totalSum = leftSum + rightSum + root->val;
        int totalCount = leftCount + rightCount + 1;

        int avg = totalSum/totalCount;
        int ans = leftAns + rightAns;
        if(avg == root->val){
            ans++;
        }
        return {totalSum, totalCount, ans};
    }
    int averageOfSubtree(TreeNode* root) {
        auto [sum, co, ans] = count(root);
        return ans;
    }
};