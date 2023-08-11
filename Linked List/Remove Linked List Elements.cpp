/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        
        while(head->val == val){
            if(head->next == NULL){
                return NULL;
            }
            head = head->next;
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr != NULL){
            //cout<<curr->val;
            //cout<<prev->val<<" ";
            if(curr->val == val){
               ListNode* temp = curr->next;
                prev->next = temp;
                curr = temp;
            }
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        
        return head;
    }
};