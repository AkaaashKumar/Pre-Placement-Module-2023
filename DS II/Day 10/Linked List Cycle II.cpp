class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    if (!head) {
      return head;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    bool are_same = false;
    while (fast->next && fast->next->next && !are_same) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        are_same = true;
      }
    }

    if (!fast->next || !fast->next->next) {
      return nullptr;
    }

    // at this point a cycle must exist and slow == fast

    // there exists at least 1 node in the cycle i.e. slow
    int cycle_length = 1;
    fast = fast->next;
    while (fast != slow) {
      fast = fast->next;
      ++cycle_length;
    }

    // cycle_length now holds the number of nodes in the cycle
    // travelling cycle_length links from a node in the cycle leads abck to the
    // original node
    // so have two pointers cycle_length links apart and then move them until
    // they equal each other. that is the first node in the cycle

    slow = head;
    fast = slow;

    for (int i = 0; i < cycle_length; ++i) {
      fast = fast->next;
    }

    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};
