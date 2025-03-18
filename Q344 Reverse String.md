# Q344 Reverse String

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp = '0';
        int l = 0, r = s.size() - 1;
        while (l < r) {
            tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
        }
    }
};
```
