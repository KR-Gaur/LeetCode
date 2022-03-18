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
    TreeNode* build(vector<int>&p, int pStart, int pEnd, vector<int>&in,
                    int inStart, int inEnd, unordered_map<int, int>& inMap){
        
        if(pEnd<pStart || inEnd<inStart) return NULL;
        
        TreeNode* node = new TreeNode(p[pStart]);
        int indexInorder = inMap[node->val];
        int numsLeft = indexInorder - inStart;
        
        node->left = build(p, pStart+1, pStart+numsLeft, in, inStart, indexInorder-1, inMap);
        node->right = build(p, pStart+numsLeft+1, pEnd, in, indexInorder+1, inEnd, inMap);
        
        return node;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int len = inorder.size();
        
        for(int i=0; i<len; i++){
            inMap[inorder[i]] = i;
        }
        
        return build(preorder, 0, len-1, inorder, 0, len-1, inMap);
    }
};