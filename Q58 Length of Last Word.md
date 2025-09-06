# Q58 Length of Last Word

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        while (index >= 0 && s[index] == ' ') {
            index--;
        }
        int counter = 0;
        while (index >= 0 && s[index] != ' ') {
            counter++;
            index--;
        }
        return counter;
    }
};
```
