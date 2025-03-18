# Q20 Valid Parentheses

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
                continue;
            }
            if (s[i] != ')' && s[i] != '}' && s[i] != ']') {
                continue;
            }
            if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(') {
                    return false;
                }
                stk.pop();
                continue;
            }
            if (s[i] == '}') {
                if (stk.empty() || stk.top() != '{') {
                    return false;
                }
                stk.pop();
                continue;
            }
            if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[') {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
```
