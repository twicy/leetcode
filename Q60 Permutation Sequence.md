# Q60 Permutation Sequence

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> dp(n - 1, 1);
        for (int i = 1; i < dp.size(); i++) {
            dp[i] = dp[i - 1] * (i + 1);
        }

        vector<int> numbers(n, 0);
        for (int i = 0; i < n; i++) {
            numbers[i] = i + 1;
        }

        string ret = "";

        k--;

        for (int fact_index = dp.size() - 1; fact_index >= 0; fact_index--) {
            int index = k / dp[fact_index];
            ret += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= dp[fact_index];
        }
        ret += to_string(numbers[0]);
        return ret;
    }
};
```
