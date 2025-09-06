# Q67 Add Binary

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans(max(a.size(), b.size()) + 1, '0');
        int carry = 0;

        int i = 0;
        while (i < a.size() || i < b.size() || carry == 1) {
            int a_num = (i < a.size()) ? (int)(a[i] - '0') : 0;
            int b_num = (i < b.size()) ? (int)(b[i] - '0') : 0;
            int sum = carry + a_num + b_num;
            ans[i] = ('0' + sum % 2);
            carry = sum / 2;
            i++;
        }
        if (ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
