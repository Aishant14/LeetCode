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
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        if(root == NULL){
            return width;
        }
        queue<pair<TreeNode*,int>> que;
        que.push({root,0});

        while(!que.empty()){
            int size = que.size();
            int  firstNodeIdx = que.front().second;
            int  lastNodeIdx = que.back().second;
            width = max(width,lastNodeIdx - firstNodeIdx +1);

            for(int i=0; i<size; i++){
                auto curr = que.front();
                que.pop();
                TreeNode* node = curr.first;
                long long idx = curr.second;
                if(node->left){
                    que.push({node->left,2*idx + 1});
                }
                if(node->right){
                    que.push({node->right,2*idx + 2});
                }
            }
        }
        return width;
    }
};