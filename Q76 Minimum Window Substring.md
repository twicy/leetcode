# Q76 Minimum Window Substring

Not very efficient

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> freq;
        for (char ch: t) {
            freq[ch]++;
        }
        auto all_freq_met = [&]()->bool {
            for (auto item: freq) {
                if (item.second > 0) return false;
            }
            return true;
        };

        int left = 0;
        int window_substr_len = INT_MAX;
        int window_substr_index = -1;
        for (int right = 0; right < s.size(); right++) {
            if (freq.find(s[right]) != freq.end()) {
                freq[s[right]]--;
            }
            while (left <= right && all_freq_met()) {
                if (right - left + 1 < window_substr_len) {
                    window_substr_index = left;
                    window_substr_len = right - left + 1;
                }
                if (freq.find(s[left]) != freq.end()) {
                    freq[s[left]]++;
                }
                left++;
            }
        }
        return (window_substr_len == INT_MAX) ? "": s.substr(window_substr_index, window_substr_len);
    }
};
```
