# Q92 Reverse Linked List II

The key is to make everything inplace: `left->next = next->next;`

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy;

        for (int i = 0; i < l - 1; i++) {
            prev = prev->next;
        }
        ListNode *left = prev->next, *next;
        for (int i = 0; i < r - l; i++) {
            next = left->next;
            left->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy.next;
    }
};
```
