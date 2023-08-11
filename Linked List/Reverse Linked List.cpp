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
     ListNode* reverse(ListNode* head){
         if(head==NULL || head->next==NULL){
             return head;
         }

         //this stores the last node and used later
         //head->next becuase we want to traverse each node and evaluate each node
         ListNode* newHead=reverse(head->next);

         //the second node will be reversed so changing its pointers
         // to reverse the direction reverse pointing of list
         head->next->next=head;
         //also changing the pointers of the head
         head->next=NULL;
        //  newhead last element ko pakad leta hai phir usko return kar deta akri me
         return newHead;
     }
  /*  void reverse(ListNode* &head,ListNode* curr,ListNode *prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        ListNode* forward=curr->next;
        reverse(head,forward,curr);
        curr->next=prev;
        
    } */
    ListNode* reverseList(ListNode* head) {
         return reverse(head);

         //iterative solution
      /*  if(head==NULL|| head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward=NULL;
        
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        
        return prev; */
    }
};