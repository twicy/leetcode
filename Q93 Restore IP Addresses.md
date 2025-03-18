# Q93 Restore IP Addresses

```cpp
class Solution {
    vector<string> res;
    bool if_valid(string s, int start, int end) {
        if (start == end) {
            return true;
        }

        if (s[start] == '0') {
            return false;
        }

        if (end - start + 1 > 3) {
            return false;
        }

        return (stoi(s.substr(start, end - start + 1)) <= 255);
    }
    void backtracking(string s, int index, string curr, int counter) {
        if (counter == 0) {
            if (index == s.size()) {
                curr.pop_back();
                res.push_back(curr);
            }
            return;
        }
        for (int i = index; i < min(index + 3, ((int)(s.size()))); i++) {
            if (if_valid(s, index, i)) {
                backtracking(s,
                i + 1,
                curr + s.substr(index, i - index + 1) + ".",
                counter - 1);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string curr = "";
        for (int i = 0; i < s.size(); i++) {
            if ('0' > s[i] && s[i] > '9') {
                return res;
            }
        }
        backtracking(s, 0, curr, 4);
        return res;
    }
};
```
