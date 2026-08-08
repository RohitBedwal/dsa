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
    TreeNode* helper(vector<int>& inorder, int inSt, int inEnd,  vector<int>& postorder, int poSt, int poEnd, unordered_map<int, int>& mpp){
        if(inSt>inEnd || poSt > poEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[poEnd]);
        int inRoot = mpp[postorder[poEnd]];
        int numsLeft = inRoot - inSt;

        root->left = helper(inorder, inSt, inRoot - 1, postorder, poSt, poSt + numsLeft - 1, mpp);
        root->right = helper(inorder, inRoot + 1, inEnd, postorder,  poSt + numsLeft, poEnd - 1, mpp);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        unordered_map <int, int> mpp;
        for(int i = 0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;

        }
        TreeNode* root = helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
        return root;
    }
};