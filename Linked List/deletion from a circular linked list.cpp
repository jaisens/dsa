void deleteNode(struct Node* head, int key)
{
    if (head == NULL)
        return;
  
    // Find the required node
    struct Node *curr = head, *prev;
    while (curr->data != key) 
    {
        if (curr->next == head)
        {
            printf("\nGiven node is not found"
                   " in the list!!!");
            break;
        }
  
        prev = curr;
        curr = curr->next;
    }
  
    // Check if node is only node
    if (curr->next == head) 
    {
        head = NULL;
        free(curr);
        return;
    }
  
    // If more than one node, check if
    // it is first node
    if (curr == head) 
    {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }
  
    // check if node is last node
    else if (curr->next == head && curr == head) 
    {
        prev->next = head;
        free(curr);
    }
    else 
    {
        prev->next = curr->next;
        free(curr);
    }
}