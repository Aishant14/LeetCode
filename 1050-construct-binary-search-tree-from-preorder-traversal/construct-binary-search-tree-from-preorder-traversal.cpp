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
    TreeNode* createBST(vector<int>& preorder,int maxxer,int& curr){
        if( curr >= preorder.size() || preorder[curr] > maxxer){
            return NULL;
        }
        TreeNode* root  = new TreeNode(preorder[curr]);
        curr++;
        root->left = createBST(preorder,root->val,curr);
        root->right = createBST(preorder,maxxer,curr);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int curr = 0;
        return createBST(preorder,INT_MAX,curr);
    }
};