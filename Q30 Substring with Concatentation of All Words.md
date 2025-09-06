# Q30 Substring with Concatentation of All Words

Fails Time Complexity

```cpp
class Solution {
    vector<int> res;
    int total_len = 0;
    bool word_match(string &s, int str_index, string &word) {
        for (int i = 0; i < word.size(); i++) {
            if (s[str_index + i] != word[i]) return false;
        }
        return true;
    }
    bool backtrack(string &s, int str_index, vector<string>& words, int word_count, vector<bool>& used) {
        if (word_count == words.size()) {
            res.push_back(str_index - total_len);
            return true;
        }

        for (int i = 0; i < words.size(); i++) {
            if (used[i]) continue;
            if (!word_match(s, str_index, words[i])) continue;
            used[i] = true;
            if (backtrack(s, str_index + words[i].size(), words, word_count + 1, used)) return true;
            used[i] = false;
        }
        return false;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        for (string word : words) {
            total_len += word.size();
        }
        vector<bool> used(words.size(), false);

        for (int i = 0; i <= (int)s.size() - total_len; i++) {
            std::fill(used.begin(), used.end(), false);
            backtrack(s, i, words, 0, used);
        }
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int word_len = words[0].size();
        unordered_map<string, int> map;
        for (string &word : words) {
            map[word]++;
        }
        for (int offset = 0; offset < word_len; offset++) {
            unsigned int size = 0;
            unordered_map<string, int> seen;
            for (int i = offset; i + word_len <= s.size(); i += word_len) {
                string substr = s.substr(i, word_len);
                if (map.find(substr) == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }
                seen[substr]++;
                size++;
                while (seen[substr] > map[substr]) {
                    string first = s.substr(i - (size - 1) * word_len, word_len);
                    seen[first]--;
                    size--;
                }
                if (size == words.size())
                    res.push_back(i - (size - 1) * word_len);
            }
        }
        return res;
    }
};
```
