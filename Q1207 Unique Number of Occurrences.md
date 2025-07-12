# Q1207 Unique Number of Occurrences

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int occur[2001] = {0};
        int freq[1001] = {0};
        for (int i = 0; i < arr.size(); i++) {
            occur[arr[i] + 1000]++;
        }
        for (int i = 0; i < 2001; i++) {
            if (occur[i] == 0) {
                continue;
            }
            if (freq[occur[i]] == 1) {
                return false;
            }
            freq[occur[i]] = 1;
        }
        return true;
    }
};
```
