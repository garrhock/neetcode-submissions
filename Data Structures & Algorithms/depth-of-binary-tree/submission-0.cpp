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
    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        calcDepth(root,1,maxDepth);
        return maxDepth;
    }
    void calcDepth(TreeNode* root, int depth, int& maxDepth){
        if(!root) return;
        maxDepth = max(maxDepth, depth);
        calcDepth(root->left, depth+1, maxDepth);
        calcDepth(root->right, depth+1, maxDepth);

    }
};
