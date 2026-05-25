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
    TreeNode* createBST(vector<int>& preorder, int start , int end){
        if(start > end){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[start]);
        int mid = start+1;
        while(mid <= end && preorder[mid] < root->val){
            mid++;
        }
        root->left = createBST(preorder,start+1,mid-1);
        root->right = createBST(preorder,mid,end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createBST(preorder,0,preorder.size()-1);
       
    }
};