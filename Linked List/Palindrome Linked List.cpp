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



//reverse the list from the middle and check if elements are same
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* newHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // to check if only one element is present or not
        if(slow->next == NULL){
            if(slow->val == head->val){
                return true;
            }
            else 
                return false;
        }
        //slow->next will not come check from dry run 
        //also no need to increase the slow pointer

        slow= reverse(slow);
        //cout<<revhead->val;
        
        
        while(slow){
            //cout<<revhead->val<<" "<<head->val;
            if(slow->val != head->val){
                return false;
            }
            
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
};