# Q27 Remove Element

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
```
