# Q1002 Find Common Characters

```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> common(26, 0);
        vector<int> curr(26, 0);

        for (auto ch : words[0]) {
            common[static_cast<int>(ch - 'a')]++;
        }

        for (int i = 0; i < words.size(); i++) {
            fill(curr.begin(), curr.end(), 0);
            for (auto ch : words[i]) {
                curr[static_cast<int>(ch - 'a')]++;
            }

            for (int j = 0; j < 26; j++) {
                common[j] = min(common[j], curr[j]);
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < common[i]; j++) {
                result.push_back(string(1, i + 'a'));
            }
        }
        return result;
    }
};
```
