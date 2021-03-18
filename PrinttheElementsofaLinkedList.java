 // problem ->https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list
 
 static void printLinkedList(SinglyLinkedListNode head) {
        if(head != null){
            System.out.println(head.data);
            printLinkedList(head.next);
        }
    }