#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(TreeNode* root){
        if(root == NULL){
            return;
        }

        TreeNode* l = NULL;
        TreeNode* r = NULL;

        if(root->left != NULL){
            l = root->left;
        }
        if(root->right != NULL){
            r = root->right;
        }

        solve(root->left);
        solve(root->right);

        root->left = NULL;
        if(l != nullptr){
            root->right = l;

            while(l->right != NULL){
                l = l->right;
            }
            l->right = r;
        }
        
        return;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};