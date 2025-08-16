# Q14 Longest Common Prefix

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        string res = "";
        bool if_exit = false;
        int index = 0;
        while (true) {
            if (strs[0].size() == index) {
                break;
            }
            char ch = strs[0][index];
            for (string str: strs) {
                if (str.size() == index || ch != str[index]) {
                    goto out;
                }
            }
            res += ch;
            index++;
        }
    out:
        return res;
    }
};
```
