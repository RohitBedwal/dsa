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
        int findMaxDistance(unordered_map<TreeNode* , TreeNode* >& parent_track, TreeNode* target){
            queue<TreeNode*> q;
            q.push(target);
            unordered_map<TreeNode*, bool> visited;
            visited[target] = true;
            int count = 0;
            while(!q.empty()){
                int size = q.size();
                int fl =0;
                for(int i = 0; i<size; i++){
                    TreeNode* curr = q.front(); q.pop();
                   if(curr->left && !visited[curr->left]){
                    fl = 1;
                    q.push(curr->left);
                    visited[curr->left] = true;
                   }
                   if(curr->right && !visited[curr->right]){
                    fl = 1;
                    q.push(curr->right);
                    visited[curr->right] = true;
                   }
                   if(parent_track[curr] && !visited[parent_track[curr]]){
                    fl = 1;
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                   }

                }
                if(fl) count++;
                
            }
            return count;
        }
        TreeNode* getParent(TreeNode* root,unordered_map<TreeNode* , TreeNode* >& parent_track, int start){
            queue <TreeNode* > q;
            q.push(root);
            TreeNode* res ;
            while(!q.empty()){
                TreeNode* curr = q.front();
                if(curr->val == start) res = curr;
                q.pop();
                if(curr->left) {
                    parent_track[curr->left] = curr;
                    q.push(curr->left);

                }
                if(curr->right) {
                    parent_track[curr->right] = curr;
                    q.push(curr->right);

                }
            }
            return res;

        }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode* > parent_track;
        TreeNode* target = getParent(root, parent_track, start);
        int maxi = findMaxDistance(parent_track, target);
        return maxi;
    }
};