# Q202 Happy Number

```cpp
class Solution {
    int get_next(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (s.find(n) == s.end()) {
            s.insert(n);
            n = get_next(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
};
```
