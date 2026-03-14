/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        string str = "";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            if(curr == NULL){
                str.append("#,");
            }
            else{
                str.append(to_string(curr->val) + ",");
            }
            if(curr != NULL){
                que.push(curr->left);
                que.push(curr->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return NULL;
        }
        stringstream ss(data);
        string val;
        getline(ss,val,',');
        TreeNode* res = new TreeNode(stoi(val));
        queue<TreeNode*> que;
        que.push(res);        

        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            //left
            getline(ss,val,',');
            if(val != "#"){
                curr->left = new TreeNode(stoi(val));
                que.push(curr->left);
            }
            getline(ss,val,',');
            if(val != "#"){
                curr->right = new TreeNode(stoi(val));
                que.push(curr->right);
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));