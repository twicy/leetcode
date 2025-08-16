# Q147 Insertion Sort List

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = NULL;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = NULL;
            if (res == NULL) {
                res = curr;
            } else if (curr->val < res->val) {
                curr->next = res;
                res = curr;
            } else {
                ListNode *it = res;
                while (it->next && !(it->val <= curr->val && curr->val <= it->next->val)) {
                    it = it->next;
                }
                curr->next = it->next;
                it->next = curr;
            }
            curr = next;
        }
        return res;
    }
};
```
