    
    //problem -> https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem
    
    static SinglyLinkedListNode insertNodeAtHead(SinglyLinkedListNode llist, int data) {
        SinglyLinkedListNode new_node = new SinglyLinkedListNode(data);
        new_node.next = llist;
        return new_node;
    }