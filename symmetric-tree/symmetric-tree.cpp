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
    bool rec(TreeNode* t, TreeNode* r){
        
        if(t==NULL && r==NULL)
           return true;
        
        if(t!=NULL && r!=NULL){
            if(t->val != r->val) 
                return false;
            if(rec(t->left, r->right))
                return rec(t->right, r->left);
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return rec(root->left, root->right);
    }
};