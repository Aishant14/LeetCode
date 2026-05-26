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
    bool twosum(TreeNode* root, int target, unordered_map<int,int> &mp){
        if(root == NULL){
            return false;
        }
        int comp = target - root->val;
        if(mp.count(comp)){
            return true;
        }
        mp[root->val]++;
        return twosum(root->left,target,mp) || twosum(root->right,target,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mp;
        return twosum(root,k,mp);
    }
};