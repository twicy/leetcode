# Q117 Populating Next Right Pointers in Each Node II

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
        if (root == NULL) return root;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (q.size() > 1) {
            Node *front = q.front();
            q.pop();
            if (front != NULL) {
                if (!q.empty()) front->next = q.front();
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            } else {
                q.push(NULL);
            }
        }
        return root;
    }
};
```
