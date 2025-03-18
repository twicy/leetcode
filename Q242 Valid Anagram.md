# Q242 Valid Anagram

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[26] = {0};
        int arr2[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            arr1[static_cast<int>(s[i] - 'a')]++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            arr2[static_cast<int>(t[i] - 'a')]++;
        }

        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
};
```
