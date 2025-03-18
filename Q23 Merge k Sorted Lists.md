# Q23 Merge k Sorted Lists

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
    ListNode *Merge2Lists(ListNode *list1, ListNode *list2) {
        ListNode dummy(0, NULL);
        ListNode *curr = &dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if (list1 != NULL) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        return dummy.next;
    }
    ListNode *Divide_n_Conquer(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }
        int mid = (left + right) / 2;
        ListNode *l1 = Divide_n_Conquer(lists, left, mid);
        ListNode *l2 = Divide_n_Conquer(lists, mid + 1, right);
        return Merge2Lists(l1, l2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        return Divide_n_Conquer(lists, 0, lists.size() - 1);
    }
};
```
