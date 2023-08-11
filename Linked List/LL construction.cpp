#include<bits/stdc++.h>

class Node{
    public :
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int main(){
    Node* node1 = new Node(10);

    cout<<node1->data;
    node1 = node1->next;

    return;
}

// for doubly linked list

class Node{
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};