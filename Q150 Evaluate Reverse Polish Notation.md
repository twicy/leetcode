# Q150 Evaluate Reverse Polish Notation

```cpp
class Solution {
public:
    unordered_map<string, function<int(int, int)>> op_map = {
        {"+", [](int a, int b) {return a + b;}},
        {"-", [](int a, int b) {return a - b;}},
        {"*", [](int a, int b) {return a * b;}},
        {"/", [](int a, int b) {return a / b;}}
    };
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
            s.push(op_map[tokens[i]](n1, n2));
        }
        return s.top();
    }
};
```
