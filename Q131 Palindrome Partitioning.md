# Q131 Palindrome Partitioning

```cpp
class Solution {
    vector<vector<string>> res;
    bool if_palidrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtrack(string s, int index, vector<string> curr) {
        if (index == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (if_palidrome(s, index, i)) {
                curr.push_back(s.substr(index, i - index + 1));
                backtrack(s, i + 1, curr);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtrack(s, 0, curr);
        return res;
    }
};
```
