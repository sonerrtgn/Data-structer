//problem -> https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem

static SinglyLinkedListNode deleteNode(SinglyLinkedListNode head, int position) {
        SinglyLinkedListNode head_koru = head;
        int count = 0;
        while(count <position -1){
            head =head.next;
            count++;
        }
        //head.next silinecek head.next.next'e ise dugumun geri kalan yapısı var kayıp etmekek için burayı kayit ediyorum.
        SinglyLinkedListNode silinecek_dugumden_sonrasi = head.next.next;
        head.next = null;
        head.next = silinecek_dugumden_sonrasi;
        return head_koru;

    }