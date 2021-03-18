    // problem -> https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
    
    static SinglyLinkedListNode insertNodeAtTail(SinglyLinkedListNode head, int data) {
       if(head == null){
           head = new SinglyLinkedListNode(data);
           return head;
       }else{
            SinglyLinkedListNode bas = head;
            SinglyLinkedListNode son;
            while(head.next != null){
                head = head.next;
            }
            son = head;
            son.next = new SinglyLinkedListNode(data);
            return bas;
       }
    }