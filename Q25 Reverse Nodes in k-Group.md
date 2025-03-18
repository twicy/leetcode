# Q25 Reverse Nodes in k-Group

key is to write the correct `reverseKGroup_once` helper function

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
    ListNode *reverseKGroup_once(ListNode *head, ListNode *tail) {
        ListNode *prev = tail;
        ListNode *curr = head, *next;

        while (curr != tail) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy, *fast = head, *slow = head;
        int counter;
        while (fast != NULL) {
            counter = k;
            slow = fast;
            ListNode *next_pev = prev->next;
            while (counter-- != 0) {
                if (fast == NULL) {
                    return dummy.next;
                }
                fast = fast->next;
            }
            prev->next = reverseKGroup_once(slow, fast);
            prev = next_pev;
        }
        return dummy.next;
    }
};
```
