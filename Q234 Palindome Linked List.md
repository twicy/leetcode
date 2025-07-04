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
        stack<int> s;
        ListNode *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (slow == NULL) {
            return true;
        } else if (fast != NULL) { // odd number of nodes
            slow = slow->next;
        }
        while (slow != NULL) {
            if (s.top() == slow->val) {
                s.pop();
                slow = slow->next;
            } else {
                return false;
            }
        }
        return s.empty();
    }
};
```
