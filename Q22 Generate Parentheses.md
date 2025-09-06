# Q22 Generate Parentheses

```cpp
class Solution {
public:
    vector<string> res;
    void recursive(int open, int closed, string curr, int n) {
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if (open < n)
            recursive(open + 1, closed, curr + "(", n);

        if (closed < open)
            recursive(open, closed + 1, curr + ")", n);
    }
    vector<string> generateParenthesis(int n) {
        recursive(0, 0, "", n);
        return res;
    }
};
```
