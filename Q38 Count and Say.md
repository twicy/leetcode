# Q38 Count and Say

```cpp
class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n);
        dp[0] = "1";
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < dp[i - 1].size(); j++) {
                int counter = 1;
                while (j != dp[i - 1].size() - 1 && dp[i - 1][j] == dp[i - 1][j + 1]) {
                    counter++;
                    j++;
                }
                dp[i] += to_string(counter) + dp[i - 1][j];
            }
        }
        return dp.back();
    }
};
```
