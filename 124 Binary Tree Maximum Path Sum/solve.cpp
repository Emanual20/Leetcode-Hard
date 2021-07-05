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
    const int inf = 0x7fffffff;
    int ans;
    int traverse(TreeNode* node){
        int x=0,y=0;
        if(!node) return 0;
        if(node->left) x=traverse(node->left);
        if(node->right) y=traverse(node->right);
        ans = max(ans, node->val + max(x,0) + max(y,0));
        return node->val + max(0,max(x,y));
    }
    int maxPathSum(TreeNode* root) {
        ans = -inf;
        traverse(root);
        return ans;
    }
};