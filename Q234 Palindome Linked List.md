# Q234 Palindome Linked List

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
    bool isPalindrome(ListNode* head) {
        ListNode temp(0, head);
        ListNode *slow = &temp, *fast = &temp;
        stack<int> stk;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            stk.push(slow->val);
        }

        if (fast == NULL) {
            stk.pop();
        }

        while (slow && slow->next) {
            slow = slow->next;
            if (stk.top() != slow->val) {
                return false;
            }
            stk.pop();
        }
        return true;
    }
};
```
