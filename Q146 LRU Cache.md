# Q146 LRU Cache

```cpp
class LRUCache {
    struct list_node{
        int key;
        int val;
        struct list_node *prev, *next;
        list_node(int key, int val) {
            this->key = key;
            this->val = val;
            prev = NULL;
            next = NULL;
        }
    };
    struct list_node *head, *tail;
    map<int, list_node *> bank;
    int capacity;

    void move_to_head(struct list_node* node) {
        if (head == tail) {
            return;
        }
        if (head == node) {
            return;
        }
        if (node == tail) {
            tail = node->prev;
        }
        (node->prev)->next = node->next;
        if (node->next) {
            (node->next)->prev = node->prev;
        }
        head->prev = node;
        node->next = head;
        head = node;
    }
    void add_to_head(struct list_node* node) {
        if (head == NULL) {
            head = node;
            tail = node;
            return;
        }

        head->prev = node;
        node->next = head;
        head = node;
    }
    void evict() {
        if (head == NULL) {
            return;
        }
        struct list_node *victim = tail;
        bank.erase(victim->key);
        if (head == tail) {
            head = NULL;
            tail = NULL;
            return;
        }
        tail = tail->prev;
        tail->next = NULL;
        delete victim;
    }

    struct list_node *get_node_by_key(int key) {
        if (bank.find(key) == bank.end()) {
            return NULL;
        }
        return bank[key];
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        struct list_node *node = get_node_by_key(key);
        if (node == NULL) {
            return -1;
        }
        move_to_head(node);
        return node->val;
    }

    void put(int key, int value) {
        struct list_node *temp = get_node_by_key(key);
        if (temp == NULL) {
            temp = new list_node(key, value);
            add_to_head(temp);
            bank[key] = temp;
            if (bank.size() > capacity) {
                evict();
            }
        } else {
            temp->val = value;
            move_to_head(temp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
