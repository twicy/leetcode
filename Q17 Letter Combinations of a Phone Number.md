# Q17 Letter Combinations of a Phone Number

```cpp
class Solution {
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    void backtracking(int start, string digits, string curr) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = start; i < digits.size(); i++) {
            int map_i = static_cast<int>(digits[i] - '0');
            for (char ch: mapping[map_i]) {
                curr += ch;
                backtracking(i + 1, digits, curr);
                curr.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return res;
        }
        backtracking(0, digits, "");
        return res;
    }
};
```
