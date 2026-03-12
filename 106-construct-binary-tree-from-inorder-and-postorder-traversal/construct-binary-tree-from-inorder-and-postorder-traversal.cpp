/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& postorder, int& postIdx,
                    unordered_map<int, int>& mp, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int rootVal = postorder[postIdx];
        postIdx--;
        TreeNode* res = new TreeNode(rootVal);
        int inPos = mp[rootVal];
        res->right = solve(postorder, postIdx, mp, inPos + 1, end);
        res->left = solve(postorder, postIdx, mp, start, inPos - 1);

        return res;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int postIdx = postorder.size() - 1;

        TreeNode* res = solve(postorder, postIdx, mp, 0, inorder.size() - 1);
        return res;
    }
};