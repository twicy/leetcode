# Q907 Squares of a Sorted Array

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int start = 0, end = nums.size() - 1;
        for (int i = res.size() - 1; i >= 0; i--) {
            if (abs(nums[start]) < abs(nums[end])) {
                res[i] = nums[end] * nums[end];
                end--;
            } else {
                res[i] = nums[start] * nums[start];
                start++;
            }
        }
        return res;
    }
};
```
