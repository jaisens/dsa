//  with no extra space
class Solution {
public:
    void copyList(Node* head){
        Node* temp = head, *n=head->next;

        while(temp){
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = n;
            temp = n;
            if(n) n = n->next;
        }

    }
    void handleRandom(Node* head){
        Node* temp = head;

        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            temp=temp->next->next;
        }
    }
    Node* detach(Node* head){
        Node* temp = head, *n;

        Node* dummy = new Node(-1);
        Node* tail = dummy;
        
        while(temp){
            tail->next= temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }

        return dummy->next;


    }
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        copyList(head);
        handleRandom(head);
        return detach(head);
    }
};

// with extra space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;

        Node* temp = head;

        while(temp!=NULL){
            Node* clone = new Node(temp->val);
            mp[temp] = clone;
            temp = temp->next; 
        }

        temp = head;
        while(temp!= NULL){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};