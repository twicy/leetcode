# Q43 Multiply Strings

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res(num1.size() + num2.size(), '0');

        for (int place2 = 0; place2 < num2.size(); place2++) {
            int n2 = num2[place2] - '0';
            for (int place1 = 0; place1 < num1.size(); place1++) {
                int n1 = num1[place1] - '0';
                int nzeros = place1 + place2;
                int product = n1 * n2 + (res[nzeros] - '0');
                res[nzeros] = (product % 10) + '0';
                res[nzeros + 1] += (product / 10);
            }
        }
        while (res.size() >= 2 && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```
