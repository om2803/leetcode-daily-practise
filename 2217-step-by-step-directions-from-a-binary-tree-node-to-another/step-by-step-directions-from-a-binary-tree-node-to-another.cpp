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
    TreeNode* Lca(TreeNode* root, int src, int dest){
        if(root==NULL)
        return NULL;

        if(root->val==src or root->val==dest){
            return root;
        }

        TreeNode* leftN= Lca(root->left, src, dest);
        TreeNode* rightN=Lca(root->right, src, dest);

        if(leftN!=NULL and rightN!=NULL)
        return root;

        if(leftN!=NULL)
        return leftN;
        return rightN; 
    }

    bool findpath( TreeNode* Lca,int target, string& path){
        if(Lca==NULL){
            return false;
        }
        if(Lca->val==target){
            return true;
        }
        path.push_back('L');
        if(findpath(Lca->left, target, path)==true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findpath(Lca->right, target, path)==true){
            return true;
        }
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA= Lca(root, startValue, destValue);

        string lca2Src="";
        string lca2Dest="";

        findpath(LCA, startValue, lca2Src);
        findpath(LCA, destValue, lca2Dest);

        string res="";
        for(int i=0;i<lca2Src.length();i++){
            res.push_back('U');
        }    

        res+=lca2Dest;
        return res;
    }
};