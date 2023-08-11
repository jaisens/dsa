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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //base case
        if(head == NULL){
            return head;
        }
        
        ListNode* nextnode = NULL;
        ListNode* currnode = head;
        ListNode* prevnode = NULL;
        
        int count = 0;

        while(currnode != NULL && count < k){
            //normal procedures 
            nextnode = currnode->next;
            currnode->next = prevnode;
            //increment the pointers by one
            prevnode = currnode;
            currnode = nextnode;
            count++;
        }
        
        //head will be the last element of the reversed first list so assuming that other groups are reversed by recursion
        //we will point the head to the pointer of the remaining elements
        head->next = reverseKGroup(nextnode,k);
        
        //after reversing the node each group's first element is prev 
        return prevnode;
        
    }
};


// 2 cases of this question
// in 2nd one if k elements are not present at last then they are not revrsed
class Solution {
public:
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int x = k;
        ListNode* p = head;

        // getting to the node which is at k
        while(x>0 && p){
            p = p->next;
            x--;
        }

        // if k nodes are present to reverse
        if(x == 0 ){
            ListNode* next = NULL;
            ListNode* curr = head;
            ListNode* prev = NULL;
            int count = 0;

            while(curr != p){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if(next!=NULL){
                head->next = reverseKGroup(next,k);
            }
            
            // prev becomes the next element after reversing
            // 
            return prev;
        }
        // else return head so the remaing will be not reversed
        else {
            return head;
        }
 
    }
};