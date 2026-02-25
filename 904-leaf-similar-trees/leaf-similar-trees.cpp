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
    void solve(TreeNode* root, vector<int>& res){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            res.push_back(root->val);
            return;
        }
        solve(root->left,res);
        solve(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
       if(root1 == NULL && root1 == NULL){
         return true;
        }
       if(root1 == NULL || root2 == NULL){
         return false;
        }
        vector<int> v1,v2;
        solve(root1,v1);
        solve(root2,v2);
        return v1 == v2;

    }
};