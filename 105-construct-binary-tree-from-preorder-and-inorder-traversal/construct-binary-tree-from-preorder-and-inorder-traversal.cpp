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
    TreeNode* solve(vector<int>& preorder, int& preIndex, 
                 unordered_map<int,int>& mp,int start,int end)
    {
        if(start > end){
            return NULL;
        }
        int rootVal = preorder[preIndex];
        preIndex++;
        TreeNode* res = new TreeNode(rootVal);
        int inPos = mp[rootVal];
        res->left = solve(preorder,preIndex,mp,start,inPos-1);
        res->right = solve(preorder,preIndex,mp,inPos+1,end);

        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int preIndex = 0;
         
        
        TreeNode* res = solve(preorder,preIndex, mp,0,preorder.size()-1);
        return res;
    }
};