# Q151 Reverse Words in a String

```cpp
class Solution {
public:
    void reverse(string& s, int start, int end) {
        char tmp;
        while (start <= end) {
            tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }

    void remove_space(string& s) {
        int counter = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }
            if (counter != 0) {
                s[counter++] = ' ';
            }
            while (i < s.size() && s[i] != ' ') {
                s[counter++] = s[i++];
            }
        }
        s.resize(counter);
    }
    string reverseWords(string s) {
        remove_space(s);
        reverse(s, 0, s.size() - 1);
        int last_index = 0;
        int i;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s, last_index, i - 1);
                last_index = i + 1;
            }
        }
        reverse(s, last_index, i - 1);
        return s;
    }
};
```
