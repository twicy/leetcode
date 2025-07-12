# Q143 Reorder List

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
    void reorderList(ListNode* head) {
        deque<ListNode *> dq;
        ListNode *curr = head;
        while (curr != NULL) {
            dq.push_back(curr);
            curr = curr->next;
        }
        ListNode dummy(0, dq.front());
        curr = &dummy;
        while (!dq.empty()) {
            curr->next = dq.front();
            dq.pop_front();
            curr = curr->next;
            if (dq.empty()) {
                curr->next = NULL;
                return;
            }
            curr->next = dq.back();
            dq.pop_back();
            curr = curr->next;
        }
        curr->next = NULL;
        return;
    }
};
```
