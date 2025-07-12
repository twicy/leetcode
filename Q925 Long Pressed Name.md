# Q925 Long Pressed Name

```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int l1 = 0, l2 = 0;
        while (l1 < name.length() && l2 < typed.length()) {
            if (name[l1] != typed[l2]) {
                if (l2 == 0) return false;
                if (typed[l2] != typed[l2 - 1]) return false;
                l2++;
            } else {
                l1++;
                l2++;
            }
        }
        if (l1 != name.length()) {
            return false;
        }
        while (l2 < typed.length() && typed[l2] == name[l1 - 1]) {
            l2++;
        }
        return (l2 == typed.length());
    }
};
```
