# Q9 Palindrome Number

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> vec;
        while (x != 0) {
            vec.push_back(x % 10);
            x /= 10;
        }
        int left = 0, right = vec.size() - 1;
        while (left <= right) {
            if (vec[left] != vec[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```
