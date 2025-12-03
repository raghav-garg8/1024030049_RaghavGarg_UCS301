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
    long long MIN = LLONG_MIN;
    long long MAX = LLONG_MAX;

    bool isBST(TreeNode * root, long long minval,long long maxval){
        if (!root) return true;
        if (root-> val <=minval || root-> val >= maxval) return false;
        return (isBST(root-> left,minval,root-> val) && isBST(root-> right,root-> val, maxval));

    }
    bool isValidBST(TreeNode* root) {
        return isBST(root,MIN,MAX);
    }
};