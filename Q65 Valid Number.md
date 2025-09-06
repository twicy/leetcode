# Q65 Valid Number

```cpp
class Solution {
public:
    inline bool is_digit(char ch) {
        return ('0' <= ch && ch <= '9');     
    }
    // pure digits without + or -
    bool is_digits(string &s, int start, int end) {
        if (start >= end) return false;
        for (int i = start; i < end; i++) {
            if (!is_digit(s[i])) return false;
        }
        return true;
    }
    // + or - followed by digits
    bool is_int(string &s, int start, int end) {
        if (start >= end) return false;
        if (s[start] != '+' && s[start] != '-')
            return is_digits(s, start, end);
        return is_digits(s, start + 1, end);
    }

    bool is_dec(string &s, int start, int end) {
        if (start >= end) return false;
        if (s[start] == '+' || s[start] == '-') start++;
        if (s[start] == '.') return is_digits(s, start + 1, end);
        if (s[end - 1] == '.') return is_digits(s, start, end - 1);
        int dot_index = s.find('.', start + 1);
        return is_digits(s, start, dot_index) && is_digits(s, dot_index + 1, end);
    }
    bool is_exp(string &s, int start, int end) {
        if (start >= end) return false;
        if (s[start] != 'e' && s[start] != 'E') return false;
        return is_int(s, start + 1, end);
    }
    bool isNumber(string s) {
        int index = 0;
        while (index < s.size() && s[index] != 'e' && s[index] != 'E') {
            index++;
        }
        // if no e or E, check if int or dec
        if (index == s.size()) return is_int(s, 0, s.size()) || is_dec(s, 0, s.size());
        return (is_int(s, 0, index) || is_dec(s, 0, index)) && is_exp(s, index, s.size());
    }
};
```
