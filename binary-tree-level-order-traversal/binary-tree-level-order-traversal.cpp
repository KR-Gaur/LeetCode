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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if( root == NULL ) return ans;
          
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> levelElements;
        while(!q.empty()){
            
            int levelsize = q.size();
            while(levelsize){
                TreeNode* t = q.front();
                q.pop();
                if(t!=NULL) {
                    levelElements.push_back(t->val);
                    q.push(t->left);
                    q.push(t->right);
                }
                levelsize--;
            }
            
            if(levelElements.size() > 0)
            ans.push_back(levelElements);
            levelElements.clear();
            
        }
            
        return ans;        
    }
};