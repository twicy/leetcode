# Q132 Palindrome Partitioning II

```cpp
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> palindrome(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 1 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++) dp[i] = i;
        for (int i = 1; i < s.size(); i++) {
            if (palindrome[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (palindrome[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[s.size() - 1];
    }
};
```
