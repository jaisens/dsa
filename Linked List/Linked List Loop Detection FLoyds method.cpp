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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return head;
        if(head->next == NULL){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // normal while loop to detect the position of slow and fast intersection
        while(slow != NULL && fast != NULL){
            if(slow->next == NULL || fast->next == NULL){
                return NULL;
            }
            
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            
            slow = slow->next;
            if(slow == fast)
                break;
        }
        
        //start loop from head and slow symultaneously and where they intersect that is the starting point of the loop
        while(head != slow){
            head = head->next;
            //check if the next is nUll or not because idk why the previous checks are not working
            if(slow->next == NULL)
                return NULL;
            else
                slow = slow->next;
        }
        
        return head;
    }
};