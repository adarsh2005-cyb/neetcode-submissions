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
    bool validate(TreeNode* root,long long minVAL,long long maxVAL){
        if(root==NULL){
            return true;
        }
        if(root->val<=minVAL || root->val>=maxVAL){
            return false;
        }
        return validate(root->left,minVAL,root->val) &&
        validate(root->right,root->val,maxVAL);
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LLONG_MIN ,LLONG_MAX);
        
    }
};
