# Q32 Longest Valid Parentheses

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int ret = 0;
        for (int i = 1; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                continue;
            }
            if (s[i - 1] == '(')  {
                dp[i] = (i - 2 >= 0) ? dp[i - 2] + 2: 2;
            } else {
                int start_index = (i + 1) - (dp[i - 1] + 2);
                if (start_index >= 0 && s[start_index] == '(') {
                    dp[i] = (start_index >= 1) ? (dp[i - 1] + 2 + dp[start_index - 1]) : (dp[i - 1] + 2);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
```
