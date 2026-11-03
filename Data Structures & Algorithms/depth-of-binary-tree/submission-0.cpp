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
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root,0);
        return res;
    }
    void dfs(TreeNode* root,int x){
        if(x>res){
            res=x;
        }
        if(!root){
            return;
        }
        dfs(root->left,x+1);
        dfs(root->right,x+1);
    }
};
