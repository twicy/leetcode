# Q25 Reverse Nodes in k-Group

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
    ListNode *reverse(ListNode *start, ListNode *end) {
        ListNode *prev = NULL;
        ListNode *curr = start, *next;
        while (curr != end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode *fast = head;
        for (int i = 0; i < k; i++) {
            if (!fast) return head;
            fast = fast->next;
        }
        ListNode *res = reverse(head, fast);
        head->next = reverseKGroup(fast, k);
        return res;
    }
};
```
