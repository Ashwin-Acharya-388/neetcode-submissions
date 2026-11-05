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
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        res =  max(res , dfs(root->left) + dfs(root->right));
        return max(1+dfs(root->left),1+dfs(root->right));
    }
};
