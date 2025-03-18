# Q150 Evaluate Reverse Polish Notation

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n1, n2;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(stoi(tokens[i]));
                continue;
            }
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            if (tokens[i] == "+") {
                s.push(n1 + n2);
            } else if (tokens[i] == "-") {
                s.push(n1 - n2);
            } else if (tokens[i] == "*") {
                s.push(n1 * n2);
            } else if (tokens[i] == "/") {
                s.push(n1 / n2);
            }
        }
        return s.top();
    }
};
```
