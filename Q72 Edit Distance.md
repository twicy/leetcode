# Q72 Edit Distance

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i < word2.size() + 1; i++) {
            dp[0][i] = i;
        }

        for (int i = 0; i < word1.size() + 1; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                if (dp[i - 1][j - 1] + 1 == dp[i][j] && word1[i - 1] == word2[j - 1]) dp[i][j]--;
            }
        }

        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
```
