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
    int sum=0;
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return sum;
    }
    void dfs(TreeNode* node,int maxval){
        if(!node){
            return;
        }
        if(node->val>=maxval){
            maxval=node->val;
            sum++;
        }
        dfs(node->left,maxval);
        dfs(node->right,maxval);
    }
};
