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
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);
    }
    bool dfs(TreeNode* node,long long y,long long z){
        if(!node){
            return true;
        }
        int x = node->val;
        if(x<=y || x>=z){
            return false;
        }
        return dfs(node->left,y,x) && dfs(node->right,x,z);
    }
};
