#include <stdio.h>

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* previous = NULL; // head node doesn't have the prev note so we are initializing the head

    while(head != NULL){
        struct ListNode* temp = head->next;
        head->next = previous;
        previous = head;
        head=temp;

    }
    return previous;
}