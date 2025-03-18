# Q3 Longest Substring Without Repeating Characters

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int left = 0, maxi = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            if (mp.find(ch) != mp.end() && mp[ch] >= left) {
                left = mp[ch] + 1;
            }
            maxi = max(maxi, right - left + 1);
            mp[ch] = right;
        }
        return maxi;
    }
};
```
