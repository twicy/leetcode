# Q148 Sort List

```cpp
class Solution {
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode *divide_n_conquer(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = nullptr;

        ListNode *l1 = divide_n_conquer(head);
        ListNode *l2 = divide_n_conquer(slow);
        return merge(l1, l2);
    }

public:
    ListNode* sortList(ListNode* head) {
        return divide_n_conquer(head);
    }
};
```
