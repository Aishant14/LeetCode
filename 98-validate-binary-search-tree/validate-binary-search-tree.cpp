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
    bool checker(TreeNode* root, long long minner, long long maxxer){
        if(root == NULL){
            return true;
        }
        if(minner >= root->val || root->val >= maxxer){
            return false;
        }
        bool left = checker(root->left,minner,root->val);
        bool right = checker(root->right,root->val,maxxer);
        return left && right;

    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        long long minner = LLONG_MIN;
        long long maxxer = LLONG_MAX;
        return checker(root,minner,maxxer);
        
        
    }
};