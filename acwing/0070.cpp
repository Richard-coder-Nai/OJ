/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> nums;
    void helper(TreeNode* root) {
        if(root==NULL) return;
        helper(root->left);
        nums.push_back(root);
        helper(root->right);
    }
    TreeNode* kthNode(TreeNode* root, int k) {
        helper(root);
        return nums[k-1];
    }
};
