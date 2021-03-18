
//problem-> https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem
static void reversePrint(SinglyLinkedListNode head) {
        SinglyLinkedListNode node_head = head;
        int eleman_sayisi = 0;
        while(head != null){
            eleman_sayisi+=1;
            head = head.next;
        }
        int[] new_array = new int[eleman_sayisi];
        int count = 0;
        while(node_head != null){
            new_array[count] = node_head.data;
            node_head = node_head.next;
            count++;
        }
        eleman_sayisi -=1;
        while(-1< eleman_sayisi){
            System.out.println(new_array[eleman_sayisi]);
            eleman_sayisi-=1;
        }
        
        

    }