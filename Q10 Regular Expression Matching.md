# Q10 Regular Expression Matching

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));

        dp[0][0] = true;

        int index = 0;
        while (index < p.size()) {
            if (index + 1 < p.size() && p[index] != '*' && p[index + 1] != '*') {
                break;
            }
            if (p[index] == '*') {
                dp[index + 1][0] = true;
                index += 1;
            } else if (index + 1 < p.size() && p[index + 1] == '*') {
                dp[index + 2][0] = true;
                index += 2;
            } else {
                break;
            }
        }

        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (p[i - 1] == '.') {
                    if (dp[i - 1][j - 1]) dp[i][j] = true;
                } else if (p[i - 1] == '*') {
                    // match 0 characters or match 1 characters
                    if (dp[i - 2][j] || dp[i - 1][j]) {
                        dp[i][j] = true;
                    }
                    if (((i >= 2 && p[i - 2] == s[j - 1]) || p[i - 2] == '.')&& dp[i][j - 1]) {
                        dp[i][j] = true;
                    }
                } else if (p[i - 1] == s[j - 1]) {
                    if (dp[i - 1][j - 1]) dp[i][j] = true;
                }
            }
        }
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout << (int)dp[i][j] << " ";
            }
            cout << "\n";
        }
        return dp[p.size()][s.size()];
    }
};
```
