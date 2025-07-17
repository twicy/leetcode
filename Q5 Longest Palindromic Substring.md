# Q5 Longest Palindromic Substring

```cpp
class Solution {
    int odd_palindrom(string& s, int index) {
        int counter = 1;
        int left = index - 1, right = index + 1;
        while (left >= 0 && right <= s.size() - 1) {
            if (s[left] == s[right]) {
                counter += 2;
                left--;
                right++;
            } else {
                return counter;
            }
        }
        return counter;
    }
    int even_palindrom(string& s, int index) {
        int counter = 0;
        int left = index, right = index + 1;
        while (left >= 0 && right <= s.size() - 1) {
            if (s[left] == s[right]) {
                counter +=  2;
                left--;
                right++;
            } else {
                return counter;
            }
        }
        return counter;
    }
public:
    string longestPalindrome(string s) {
        int maxi = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            int odd_len = odd_palindrom(s, i);
            int even_len = even_palindrom(s, i);
            if (odd_len > maxi) {
                maxi = odd_len;
                ans = s.substr(i + 1 - odd_len / 2, odd_len);
            }
            if (even_len > maxi) {
                maxi = even_len;
                ans = s.substr(i + 1 - even_len / 2, even_len);
            }
        }
        return ans;
    }
};
```
