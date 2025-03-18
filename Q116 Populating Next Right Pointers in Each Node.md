# Q116 Populating Next Right Pointers in Each Node

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void bfs(Node *root) {
        if (root == NULL) {
            return;
        }
        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        bool next_level = false;
        Node *prev = NULL;
        while (!q.empty()) {
            Node *front = q.front();
            q.pop();

            if (prev != NULL) {
                prev->next = front;
            }
            if (front == NULL && !q.empty()) {
                q.push(NULL);
            }
            if (front != NULL) {
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            prev = front;
        }
    }
public:
    Node* connect(Node* root) {
        bfs(root);
        return root;
    }
};
```

The magical recursion solution:

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(root == nullptr || root->left == nullptr || root->right == nullptr)
            return root;

        root->left->next = root->right;

        if(root->next != nullptr)
            root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
        
    }
};
```
