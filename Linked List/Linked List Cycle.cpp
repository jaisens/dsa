class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        //here && means both slow and fast should be non null 
        while(slow != NULL && fast != NULL){
            //if anywhere null is found then loop is not present
            if(fast->next == NULL || slow->next == NULL ){
                return false;
            }
            
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }
        //by default it will be false
        return false;
    }
};