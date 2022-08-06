class Solution {
    public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return (k == 1)? head : Iterative(head, k); 
    }
  
    private:
    ListNode* Recursive(ListNode* head, int k) {
        if(ListNode* tail = next(head, k-1); !tail){
            return head;
        }else{
            reverseRange(head, tail);
            // now `tail` points to the new head
            //     `head` points to the new tail
            head->next = Recursive(head->next, k);
            return tail;
        }
    }
    ListNode* Iterative(ListNode* head, int k) {
        ListNode*  p1 = head;
        ListNode*  p2 = next(head, k-1);
        ListNode*  newhead = nullptr;
        ListNode** prelink = &newhead; 
        while(p2){
            // 1st iter  : Set newhead to p2
            // otherwise : Connect the previous section with this one 
            *prelink = reverseRange(p1, p2);
            // now p1 points to the new tail, and p2 points to the new head
            // Points to the `next` of the tail of this section
            prelink  = &p1->next;
            // Next section starts from the next of the tail
            p1       = p1->next; 
            // Next section ends at the k-1th node after its head
            p2       = next(p1, k-1);
        }
        return newhead;
    }

    // Reverse a closed interval [a, b]
    ListNode* reverseRange(ListNode* a, ListNode* b){
        ListNode* pre = b->next, // Points `pre` to the node that `now` should connet to
                * now = a;
        for(ListNode* nxt = now->next; nxt != b->next; nxt = nxt->next){
            now->next = pre;
            pre = exchange(now, nxt);
        }
        now->next = pre;
        return now;
    }

    // Get the nth next node, stop if null
    ListNode* next(ListNode* n, size_t k) {
        for(size_t i = 0; n && i < k; ++i)
            n = n->next;
        return n;
    }
};
