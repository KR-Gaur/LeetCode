/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*, bool> m;
        ListNode *Ahead = headA, *Bhead = headB;
        while(Ahead != NULL){
            m[Ahead]=true;
            Ahead=Ahead->next;
        }
        
        while(Bhead != NULL){
            if(m.find(Bhead) != m.end())
                break;
            Bhead = Bhead->next;
        }
        
        return Bhead;       
        
    }
};