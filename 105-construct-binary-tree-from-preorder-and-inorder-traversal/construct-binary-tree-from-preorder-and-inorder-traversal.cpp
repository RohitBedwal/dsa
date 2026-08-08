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
    private:
        TreeNode* helper(vector<int>& preorder,int preSt, int preEnd, vector<int>& inorder,int inSt, int inEnd, unordered_map<int, int>& mpp ){
            if(preSt > preEnd || inSt > inEnd) return NULL;
            TreeNode* root = new TreeNode(preorder[preSt]);
            int inRoot = mpp[root->val];
            int numsLeft = inRoot - inSt ;
            root->left = helper(preorder, preSt + 1, preSt + numsLeft, inorder, inSt, inRoot - 1, mpp);
            root->right = helper(preorder, preSt + numsLeft + 1, preEnd, inorder, inRoot + 1,inEnd, mpp);
            return root;
        }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for(int i = 0; i<preorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mpp);
        return root;
    }
};