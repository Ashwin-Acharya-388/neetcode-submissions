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
int x=-1;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return x;
    }
    void dfs(TreeNode* node, int &k){
        if(!node) return;
        dfs(node->left,k);
        k--;
        if(k==0){
            x=node->val;
            return;
        }
        dfs(node->right,k);
    }
};