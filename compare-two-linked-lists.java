// problem ->https://www.hackerrank.com/challenges/compare-two-linked-lists/problem
static boolean compareLists(SinglyLinkedListNode head1, SinglyLinkedListNode head2) {
        int count =1;
        while(count==1){
            if(head1.next == null && head2.next == null){
                return true;
            }
            if(head1.next != null && head2.next == null){
                return false;
            }
            if(head1.next == null && head2.next != null){
                return false;
            }
            if(head1.data != head2.data){
                return false;
            }
            head1=head1.next;
            head2=head2.next;
        }
        return false;

    }