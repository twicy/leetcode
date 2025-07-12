# Q922 Sort Array By Parity II

```cpp
class Solution {
public:
    int next_odd(vector<int>& nums, int curr) {
        for (int i = curr + 1; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                return i;
            }
        }
        return -1;
    }
    int next_even(vector<int>& nums, int curr) {
        for (int i = curr + 1; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                return i;
            }
        }
        return -1;
    }
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd_index = next_odd(nums, -1);
        int even_index = next_even(nums, -1);
        vector<int> res(nums.size());

        for (int i = 0; i < res.size(); i++) {
            if (i % 2 == 0) {
                res[i] = nums[even_index];
                even_index = next_even(nums, even_index);
            } else {
                res[i] = nums[odd_index];
                odd_index = next_odd(nums, odd_index);
            }
        }
        return res;
    }
};
```
