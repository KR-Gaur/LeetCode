/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        Node* cp = NULL;
        if(head == NULL) return cp;
        
        Node* h = head;
        unordered_map<Node*, Node*> m;

        while(h!=NULL){
            m[h] = new Node(h->val);
            h = h->next;
        }
        
        h = head;
        while(h!=NULL){
            m[h]->next = m[h->next];
            m[h]->random = m[h->random];
            h=h->next;
        }
        return m[head];
    }
};