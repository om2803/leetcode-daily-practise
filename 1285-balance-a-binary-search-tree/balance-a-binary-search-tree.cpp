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
    void inorder(TreeNode* root, vector<int> &arr){
        if (root==NULL)
        return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* balanceBST(vector<int>& nodes, int start, int end){
        if(start>end)
        return NULL;

        int mid=(start+end)/2;

        TreeNode* temp=new TreeNode(nodes[mid]);
        temp->left=balanceBST(nodes, start, mid-1);
        temp->right=balanceBST(nodes, mid+1, end);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return balanceBST(arr,0,arr.size()-1);

    }
};