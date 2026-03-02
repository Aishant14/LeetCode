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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        queue<TreeNode*> que;
        que.push(root);
        bool LP = true;

        while(!que.empty()){
            int size = que.size();
            vector<int> level(size);

            for(int i=0; i<size; i++){
                TreeNode* curr = que.front();
                que.pop();
                int idx = i;
                if(!LP){
                    idx = size-1-i;
                }
                level[idx] = curr->val;
                
                if(curr->left != NULL){
                    que.push(curr->left);
                }
                if(curr->right != NULL){
                    que.push(curr->right);
                }
            }
            result.push_back(level);
            LP = !LP;
        }
        return result;
    }
};