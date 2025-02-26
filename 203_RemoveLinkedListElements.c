struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    
    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next;
            free(curr);
        } else {
            prev = curr;
        }
        curr = prev->next;
    }
    
    head = dummy->next;
    free(dummy);
    return head;
}


