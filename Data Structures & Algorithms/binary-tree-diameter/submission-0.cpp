/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int maxDepth(TreeNode* root,int &maxd) {
        if(root==NULL){
            return 0;
        }
        int right = maxDepth(root->right,maxd);
        int left = maxDepth(root->left,maxd);
        maxd=max(maxd,right+left);
        return 1 + max(left,right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd = 0;
        maxDepth(root, maxd);
        return maxd;
    }
};
   

