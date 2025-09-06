# Q28 Find the Index of the First Occurrence in a String

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            for (int j = 0; j < needle.size(); j++) {
                if (needle[j] != haystack[i + j]) {
                    goto next_ch;
                }
            }
            return i;
        next_ch:
        }
        return -1;
    }
};
```
