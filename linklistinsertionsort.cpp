Node* sorted_insert(Node* sorted, Node* new_node) {
    if (sorted == NULL || new_node->data < sorted->data) {
        new_node->next = sorted;
        return new_node;
    }

    Node* current = sorted;
    while (current->next != NULL && current->next->data < new_node->data) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
    return sorted;
}

void insertion_sort(Node* list) {
    if (list == NULL || list->next == NULL)
        return;

    Node* unsorted = list->next;
    Node* sorted = NULL;

    list->next = NULL;  
    while (unsorted != NULL) {
        Node* current = unsorted;
        unsorted = unsorted->next;
        current->next = NULL;
        sorted = sorted_insert(sorted, current);
    }

    Node* curr = list;
    Node* sorted_curr = sorted;

    while (sorted_curr != NULL) {
        curr->next = sorted_curr;
        curr = curr->next;
        sorted_curr = sorted_curr->next;
    }
}

