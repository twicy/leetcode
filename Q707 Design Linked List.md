# Q707 Design Linked List

```cpp
class MyLinkedList {
    ListNode *head;
    ListNode *tail;
public:
    void print_list() {
        for (ListNode *curr = head; curr != tail; curr = curr->next) {
            if (curr == NULL) {
                return;
            }
            cout << curr->val << " ";
        }
        cout << "\n";
    }
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    int get(int index) {
        // print_list();
        ListNode *curr = head;

        for (int i = 0; i < index; i++) {
            if (curr == NULL) {
                return -1;
            }
            curr = curr->next;
        }
        if (curr == NULL) {
            return -1;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        // print_list();
        if (head == NULL) {
            head = new ListNode(val, NULL);
            tail = head;
            return;
        }
        head = new ListNode(val, head);
    }
    
    void addAtTail(int val) {
        // print_list();
        if (tail == NULL) {
            tail = new ListNode(val, NULL);
            head = tail;
            return;
        }
        tail->next = new ListNode(val, NULL);
        tail = tail->next;
    }
    
    void addAtIndex(int index, int val) {
        // print_list();
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode *curr = head;
        for (int i = 0; i < index - 1; i++) {
            if (curr == NULL) {
                return;
            }
            curr = curr->next;
        }
        if (curr == NULL) {
            return;
        }
        ListNode *next = curr->next;
        curr->next = new ListNode(val, next);
        if (next == NULL) {
            tail = curr->next;
        }
    }
    
    void deleteAtIndex(int index) {
        // print_list();
        ListNode dummy(0, head);
        ListNode *curr = &dummy;
        for (int i = 0; i < index; i++) {
            if (curr == NULL) {
                return;
            }
            curr = curr->next;
        }

        if (curr == NULL || curr->next == NULL) {
            return;
        }
        curr->next = curr->next->next;
        if (curr->next == NULL) {
            tail = curr;
        }
        head = dummy.next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```
