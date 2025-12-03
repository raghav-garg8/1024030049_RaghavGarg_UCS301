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
    void inorder(TreeNode* root, vector<int> * arr){
        if(root -> left != nullptr) inorder(root-> left, arr);
        arr->push_back(root->val);
        if(root-> right != nullptr) inorder(root-> right, arr);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes = {};
        if (root == nullptr ) {return nodes;}
        inorder(root, &nodes);
        return nodes;
    }
};
// only order swap in pre and post
