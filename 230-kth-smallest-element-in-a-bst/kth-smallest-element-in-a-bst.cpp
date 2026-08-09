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
    TreeNode* func(TreeNode* root, int& count, int k){
        if(root == NULL) return NULL;
        
        TreeNode* left = func(root->left, count, k);
        if (left) return left;
        count++;
        if(count == k){
            return root;
        }
        return func(root->right, count, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
       TreeNode* ans = func(root,count, k );
       return ans->val;
    }
};