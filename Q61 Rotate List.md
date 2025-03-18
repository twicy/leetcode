# Q61 Rotate List

Not very interesting

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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode dummy(0, head);
        int length = 0;

        ListNode *curr = head;
        while (curr != NULL) {
            curr = curr->next;
            length++;
        }
        if (length == 0) {
            return NULL;
        }
        k = k % length;

        ListNode *slow = &dummy, *fast = &dummy;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = dummy.next;
        dummy.next = slow->next;
        slow->next = NULL;

        return dummy.next;
    }
};
```
