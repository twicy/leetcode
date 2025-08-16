# Q82 Remove Duplicates from Sorted List II

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);

        ListNode *curr = head, *prev = &dummy;
        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                while (curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};
```

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *curr = &dummy;
        while (curr->next && curr->next->next) {
            ListNode *next = curr->next;
            int val = next->val;
            if (next->next && next->next->val == val) {
                while (next->next && next->next->val == val) {
                    next = next->next;
                }
                curr->next = next->next;
                continue;
            } else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
```
