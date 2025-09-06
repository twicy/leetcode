# Q66 Plus One

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int index = (int)digits.size() - 1;
        while (index >= 0) {
            int sum = digits[index] + carry;
            if (sum < 10) {
                digits[index] = sum;
                carry = 0;
                break;
            }
            digits[index] = sum % 10;
            carry = sum / 10;
            index--;
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
```
