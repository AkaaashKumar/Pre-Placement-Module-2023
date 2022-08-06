class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *dummyHead = new ListNode(0, head);
    ListNode *prev = dummyHead;
    ListNode *t = head;
    ListNode *next;
    while (t && t->next) {
      next = t->next->next;

      prev->next = t->next;
      prev->next->next = t;
      prev->next->next->next = next;

      prev = prev->next->next;
      t = next;
    }
    if(t){
        prev->next = t;
    }

    return dummyHead->next;
  }
};
