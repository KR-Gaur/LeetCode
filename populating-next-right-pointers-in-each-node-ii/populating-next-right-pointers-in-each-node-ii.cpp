/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if( root ==NULL )
            return root;
        
        queue<Node*> q;
        q.push(root);
        int pushedCount =1;
        while(!q.empty()){
            Node* t = q.front();
            // q.pop();
            // pushedCount--;
            int pushedChildrenCount =0;
            while(pushedCount){
                Node* temp = q.front();
                t->next = temp;
                q.pop();
                t=t->next;
                if(temp->left!=NULL){
                    q.push(t->left);
                    pushedChildrenCount++;
                }
                if(temp->right!=NULL){
                    q.push(t->right);
                    pushedChildrenCount++;
                }
                pushedCount--;
            }
            t->next = NULL;
            pushedCount = pushedChildrenCount;
        }
        return root;
    }
};