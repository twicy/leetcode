# Q68 Text Justification

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int left = 0, right = 0;
        int words_len = 0;
        vector<string> res;
        while (right < words.size()) {
            int proposed_len = words_len + words[right].size() + (right - left);
            // cout << "b1 " << left << " " << right << " " << proposed_len << endl;
            if (proposed_len <= maxWidth) {
                words_len += words[right].size();
                right++;
            } else {
                // [left, right)
                // cout << "b2 " << left << " " << right << endl;
                int nspaces = maxWidth - words_len;
                int nwords = right - left;
                int i = 0, offset = 0;
                string line(maxWidth, ' ');
                if (nwords == 1) {
                    copy(words[left].begin(), words[left].end(), line.begin());
                } else {
                    for (; i < nspaces % (nwords - 1); i++) {
                        copy(words[left + i].begin(), words[left + i].end(),line.begin() + offset);
                        offset += words[left + i].size() + nspaces / (nwords - 1) + 1;
                    }
                    for (; left + i < right; i++) {
                        copy(words[left + i].begin(), words[left + i].end(),line.begin() + offset);
                        offset += words[left + i].size() + nspaces / (nwords - 1);
                    }
                }
                res.push_back(line);
                words_len = 0;
                left = right;
            }
        }
        int offset = 0;
        string line(maxWidth, ' ');
        for (int i = left; i < words.size(); i++) {
            copy(words[i].begin(), words[i].end(),line.begin() + offset);
            offset += words[i].size() + 1;
        }
        res.push_back(line);
        return res;
    }
};
```
