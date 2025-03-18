# Q343 Integer Break

```cpp
class Solution {
public:
    int integerBreak(int n) {
        vector<int> res(n + 1, 0);

        res[0] = 0;
        res[1] = 1;
        res[2] = 1;

        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j < i; j++) {
                res[i] = max(res[i], max(i - j, res[i - j]) * j);
            }
        }
        return res[n];
    }
};
```
