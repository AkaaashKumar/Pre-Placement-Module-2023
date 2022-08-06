class MyLinkedList {
    class ListNode {
        int val;
        ListNode next;
        public ListNode(int x) {
            this.val = x;
        }
    }
    ListNode head;
    ListNode tail;
    int size;

    /** Initialize your data structure here. */
    public MyLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if(index < 0 || index >= size) {
            return -1;
        }
        ListNode cur = head;
        while(index > 0) {
            cur = cur.next;
            index--;
        }
        return cur.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        ListNode newHead = new ListNode(val);
        newHead.next = head;
        head = newHead;
        if(tail == null) {
            tail = head;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        ListNode newTail = new ListNode(val);
        if(tail == null) {
            head = new ListNode(val);
        } else {
            tail.next = newTail;
        }
        tail = newTail;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if(index < 0 || index > size) {
            return;
        }
        ListNode node = new ListNode(val);
        if(index == 0) {
            addAtHead(val);
            return;
        }
        if(index == size) {
            addAtTail(val);
            return;
        }
        ListNode cur = head;
        while(index > 1) {
            cur = cur.next;
            index--;
        }
        ListNode tmp = cur.next;
        cur.next = node;
        node.next = tmp;
        
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if(size == 0 || index < 0 || index >= size) {
            return;
        }
        if(index == 0) {
            if(size == 1) {
                head = null;
                tail = null;
                size = 0;
                return;
            }
            head = head.next;
            size--;
            return;
        } else {
            ListNode cur = head;
            int cnt = index;
            while(cnt > 1) {
                cur = cur.next;
                cnt--;
            }
            if(index == size - 1) {
                tail = cur;
                tail.next = null;
                size--;
                return;
            }
            cur.next = cur.next.next;
            size--;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
