# Q8 String to Integer (atoi)

```cpp
class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int index = 0;
        // ignore leading whitespace
        while (index < s.size() && s[index] == ' ') index++;
        if (index == s.size()) return res;
        bool if_negative = false;
        if (s[index] == '-') {
            index++;
            if_negative = true;
        } else if (s[index] == '+') {
            index++;
        }

        // skip leading zeros
        while (index < s.size() && s[index] == '0') index++;
        if (index == s.size()) return res;
        while (index < s.size() && '0' <= s[index] && s[index] <= '9') {
            res = res * 10 + (int)(s[index] - '0');
            if (!if_negative && res > INT_MAX) {
                return INT_MAX;
            }
            if (if_negative && -res < INT_MIN) {
                return INT_MIN;
            }
            index++;
        }
        return if_negative ? -res : res;
    }
};
```
