#include<iostream>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(l!=0 && r!=0){
            return min(l,r)+1;    
        }
        return l+r+1;
    }
};