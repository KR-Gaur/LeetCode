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
    
    int rec(TreeNode* root, int &count){
        
        if( root == NULL ) return 0;

        int left = rec(root->left, count); 
        int right = rec(root->right, count);
        
        if( root->left == NULL && root->right == NULL ) 
            return 3;
        
        if( left == 3 || right == 3 ) { 
            count++;
            return 1;
         }
        if( root->left !=NULL && root->right != NULL)
            return 1 + min(left, right);
        else if( root->left == NULL)
            return 1+right;
        else return 1+left;
        
    }
    
public:
    int minCameraCover(TreeNode* root) {          
        int count = 0;
        int temp = rec(root, count);
        if( temp==3 ) count++;
        return count;
    }
};