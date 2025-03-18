# Q383 Ransom Note

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag_arr[26] = {0};
        for (char ch : magazine) {
            mag_arr[static_cast<int>(ch - 'a')]++;
        }
        for (char ch : ransomNote) {
            if (mag_arr[static_cast<int>(ch - 'a')] == 0) {
                return false;
            }
            mag_arr[static_cast<int>(ch - 'a')]--;
        }
        return true;
    }
};
```
