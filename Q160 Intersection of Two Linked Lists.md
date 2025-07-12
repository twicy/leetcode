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

        while (l1 && l2) {
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2) {
            while (l2) {
                headB = headB->next;
                l2 = l2->next;
            }
        }
        
        if (l1) {
            while (l1) {
                headA = headA->next;
                l1 = l1->next;
            }
        }

        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
```
