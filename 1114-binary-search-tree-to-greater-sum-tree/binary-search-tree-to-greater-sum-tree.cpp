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
    int nodeSum=0;
    void revInorder(TreeNode* root){
        if(root==NULL)
        return;

        if(root){
            revInorder(root->right);
            nodeSum+=root->val;
            root->val=nodeSum;
            revInorder(root->left);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        revInorder(root);
        return root;
    }
};