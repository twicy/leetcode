# Q13 Roman to Integer

```cpp
class Solution {
public:
    unordered_map<char, int> symbols = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };
    int romanToInt(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int curr = symbols[s[i]];
            int next = (i == s.size() - 1) ? 0 : symbols[s[i + 1]];

            if (curr < next) {
                res -= curr;
            } else {
                res += curr;
            }
        }
        return res;
    }
};
```
