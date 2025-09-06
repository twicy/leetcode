# Q97 Interleaving String

Time Limit Exceeded

```cpp
class Solution {
public:
    string s1;
    string s2;
    string s3;
    bool backtracking(int i1, int i2, int i3, int next) {
        if (i1 == s1.size() && i2 == s2.size() && i3 == s3.size()) return true;
        if ((i1 == s1.size() || i2 == s2.size()) && i3 == s3.size()) return false;
        // use i1 substr
        // cout << i1 << " " << i2 << " " << i3 << " " << next << endl;
        if (next == 1) {
            for (int next_i1 = i1, next_i3 = i3; next_i1 < s1.size() && next_i3 < s3.size(); next_i1++, next_i3++) {
                if (s1[next_i1] == s3[next_i3] && backtracking(next_i1 + 1, i2, next_i3 + 1, 2)) return true;
                else if (s1[next_i1] != s3[next_i3]) break;
            }
        } else {
            for (int next_i2 = i2, next_i3 = i3; next_i2 < s2.size() && next_i3 < s3.size(); next_i2++, next_i3++) {
                if (s2[next_i2] == s3[next_i3] && backtracking(i1, next_i2 + 1, next_i3 + 1, 1)) return true;
                else if (s2[next_i2] != s3[next_i3]) break;
            }
        }
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        return backtracking(0, 0, 0, 1) || backtracking(0, 0, 0, 2);
    }
};
```

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;

        for (int i = 1; i < (int)dp.size(); i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int i = 1; i < (int)dp[0].size(); i++) {
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];
        }
        for (int i = 1; i < (int)dp.size(); i++) {
            for (int j = 1; j < (int)dp[0].size(); j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                            (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
```
