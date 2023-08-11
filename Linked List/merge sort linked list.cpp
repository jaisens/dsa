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

    ListNode* findmiddle(ListNode* head){
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next;
            if(!fast->next){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* a, ListNode* b){

        if(b == NULL){
            return a;
        }

        if(a == NULL) return b;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(a!=NULL && b!=NULL){
            if(a->val < b->val){
                temp->next = a;
                temp = a;
                a = a->next;
            }
            else{
                temp->next = b;
                temp = b;
                b = b->next;
            }
        }

        while(a!=NULL){
            temp->next = a;
            temp = a;
            a = a->next;
        }

        while(b!=NULL){
            temp->next = b;
            temp = b;
            b = b->next;
        }

        return ans->next;

    }

    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* middle = findmiddle(head);
        // add the middle function here only

        ListNode* a = head;
        ListNode* b = middle->next;
        
        // breaking from middle
        middle->next = NULL;

        // break using recursion
        a = sortList(a);
        b = sortList(b);

        ListNode* result = merge(a,b);

        return result;
    }
};