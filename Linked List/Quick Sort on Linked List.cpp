void swapVal(node* first, node* sec){
    int temp = first->data;
    first->data = sec->data;
    sec->data = temp;
}

node* partition(node* start, node* end){
    int pivotal = start->data;
    node* i = start;
    node* j = start->next;
    
    while(j != end){
        
        if(j->data < pivotal){
            i = i->next;
            swapVal(i,j);
        }
        
        j = j->next;
    }
    // i will be at the last element which is smaller than ppivot element
    // so placing the pivot element at that index
    swapVal(i,start);
    return i;
}

void QuickSort(node * start, node * end){
    if(start != end){
        node* pivot = partition(start,end);
        QuickSort(start, pivot);
        QuickSort(pivot->next, end);
    }
}
void quickSort(struct node **headRef) {
    
    
    QuickSort(*headRef,NULL);
    
}