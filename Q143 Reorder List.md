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
    void print_list(ListNode *head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << "\n";
    }
public:
    void reorderList(ListNode* head) {
        deque<ListNode *> dq;
        ListNode *curr = head;
        while (curr != NULL) {
            dq.push_back(curr);
            curr = curr->next;
        }
        curr = dq.front();
        while (!dq.empty()) {
            curr->next = dq.front();
            dq.pop_front();
            curr = curr->next;
            curr->next = NULL;
            if (dq.empty()) {
                curr->next = NULL;
            } else {
                curr->next = dq.back();
                dq.pop_back();
                curr = curr->next;
                curr->next = NULL;
            }
        }
        // print_list(head);
    }
};
```
