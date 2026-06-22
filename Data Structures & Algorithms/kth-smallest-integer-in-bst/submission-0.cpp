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
    void search(TreeNode* root , vector<int> &arr){
        if(!root)return;
        arr.push_back(root->val);
        search(root->left,arr);
        search(root->right,arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        search(root,arr);
        sort(arr.begin(),arr.end());
        return arr[k-1];


        
    }
};
