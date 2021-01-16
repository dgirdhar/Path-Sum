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
    
    bool GetPathSum(TreeNode* root, int sum) {
        bool ret = false;
        
        if (root != nullptr) {
            int remainingSum = sum - root->val;

            if (root->left == nullptr && root->right == nullptr && remainingSum == 0) {
                ret = true;             
            }
            else {
                ret = GetPathSum(root->left, remainingSum);
                if (!ret) {
                    ret = GetPathSum(root->right, remainingSum);
                }
            }
        }
        
        return ret;
    }
        
    bool hasPathSum(TreeNode* root, int sum) {
        return GetPathSum(root, sum);    
    }
};
