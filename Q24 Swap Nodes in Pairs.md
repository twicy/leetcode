# Q24 Swap Nodes in Pairs

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *curr = &dummy;
        ListNode *first = NULL, *second = NULL;
        while (curr && curr->next && curr->next->next) {
            first = curr->next;
            second = curr->next->next;

            first->next = second->next;
            curr->next = second;
            second->next = first;
            curr = first;
        }
        return dummy.next;
    }
};
```
