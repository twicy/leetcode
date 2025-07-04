# Q160 Intersection of Two Linked Lists

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1 = headA, *l2 = headB;
        int diff = 0;
        while (l1 && l2) {
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) {
            while (l1) {
                l1 = l1->next;
                diff++;
            }
            for (int i = 0; i < diff; i++) {
                headA = headA->next;
            }
        } else if (l2) {
            while (l2) {
                l2 = l2->next;
                diff++;
            }
            for (int i = 0; i < diff; i++) {
                headB = headB->next;
            }
        }
        while (headA && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
```
