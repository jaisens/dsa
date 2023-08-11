//HashMap Solution

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode*, int> m;
		while(headA != NULL){
			m[headA]++;
			headA = headA -> next;
		}
		while(headB != NULL){
			if(m[headB] > 0){
				return headB;
			}
			headB = headB -> next;
		}
		return NULL;
	}
};

//Length Difference Solution
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int n = 0;
		int m = 0;
		ListNode* ptr1 = headA;
		ListNode* ptr2 = headB;
		while(ptr1 != NULL){
			n++;
			ptr1 = ptr1 -> next;
		}
		while(ptr2 != NULL){
			m++;
			ptr2 = ptr2 -> next;
		}
		int t = abs(n - m);
		if(n > m){
			while(t){
				headA = headA -> next;
				t--;
			}
		}
		else{
			while(t){
				headB = headB -> next;
				t--;
			}
		}
		while(headA != NULL and headB != NULL){
			if(headA == headB){
				return headA;
			}
			headA = headA -> next;
			headB = headB -> next;
		}
		return NULL;
	}
};

//Two-Pointers Solution
lass Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;
		while(ptr1 != ptr2){
			if(ptr1 == NULL){
				ptr1 = headB;
			}
			else{
				ptr1 = ptr1 -> next;
			}
			if(ptr2 == NULL){
				ptr2 = headA;
			}
			else{
				ptr2 = ptr2 -> next;
			}
		}
		return ptr1;
	}
};