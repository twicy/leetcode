# Q35 Search Insert Position

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                if (mid == (nums.size() - 1) || target < nums[mid + 1]) {
                    return mid + 1;
                }
                left = mid + 1;
            } else if (nums[mid] > target) {
                if (mid == 0) {
                    return 0;
                }
                if (target > nums[mid - 1]) {
                    return mid;
                }
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
```