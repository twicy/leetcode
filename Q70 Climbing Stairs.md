# Q70 Climbing Stairs

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n + 1, 0);

        res[0] = 1;
        res[1] = 1;

        for (int i = 2; i < res.size(); i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res.back();
    }
};
```
