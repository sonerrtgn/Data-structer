

//problem-> https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    int count = 0;
    struct SinglyLinkedListNode *iter = head;
    while(count < position-1){
        iter = iter->next;
        count++;
    }
    struct SinglyLinkedListNode *iter_next_tut = iter->next;
    iter->next = (struct SinglyLinkedListNode *)malloc(sizeof(struct SinglyLinkedListNode));
    iter->next->data=data;
    iter->next->next=iter_next_tut;
    
    return head;


}