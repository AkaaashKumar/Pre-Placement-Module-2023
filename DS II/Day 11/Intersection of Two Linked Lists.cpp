class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        int end = 0;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa->next && pb->next) {
            pa = pa->next;
            pb = pb->next;
        }
        ListNode *tmp, *temp;
        if (pa->next) {
            tmp = pa;
            temp = pb;
            pa = headA;
            pb = headB;
            while (tmp->next) {
                tmp = tmp->next;
                pa = pa->next;
            }
            if (tmp != temp) {
                return NULL;
            }
            while (pa != pb) {
                pa = pa->next;
                pb = pb->next;
            }
        } else {
            tmp = pb;
            temp = pa;
            pa = headA;
            pb = headB;
            while (tmp->next) {
                tmp = tmp->next;
                pb = pb->next;
            }
            if (tmp != temp) {
                return NULL;
            }
            while (pa != pb) {
                pa = pa->next;
                pb = pb->next;
            }
        }
        
        return pa;
    }
};
