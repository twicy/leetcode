# Q509 Fibonacci Number

```cpp
class Solution {
public:
    int fib(int n) {
        vector<int> res(n + 1, 0);

        if (n == 0 || n == 1) {
            return n;
        }
        res[1] = 1;
        for (int i = 2; i < res.size(); i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res.back();
    }
};
```
