# Q34 Find First and Last Position of Element in Sorted Array

```cpp
class Solution {
    int find_first(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                if (mid == 0) {
                    return 0;
                } else if (nums[mid - 1] != target){
                    return mid;
                } else {
                    end = mid - 1;
                }
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    int find_last(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1) {
                    return mid;
                } else if (nums[mid + 1] != target){
                    return mid;
                } else {
                    start = mid + 1;
                }
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        res[0] = find_first(nums, target);
        res[1] = find_last(nums, target);
        return res;
    }
};
```
