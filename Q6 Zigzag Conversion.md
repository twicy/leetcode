# Q6 Zigzag Conversion

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> res(numRows, "");
        int index = 0;
        while (index < s.size()) {
            for (int i = 0; i < (numRows - 1) && index < s.size(); i++, index++) {
                res[i] += s[index];
            }
            if (index >= s.size()) {
                break;
            }
            for (int i = numRows - 1; (i >= 1) && index < s.size(); i--, index++) {
                res[i] += s[index];
            }
        }
        for (int i = 1; i < res.size(); i++) {
            res[0] += res[i];
        }
        return res[0];
    }
};
```
