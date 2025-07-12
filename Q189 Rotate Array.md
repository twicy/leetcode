# Q189 Rotate Array

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int *arr = (int *)malloc(sizeof(int) * k);
        if (arr == NULL) {
            return;
        }
        for (int i = n - k; i < n; i++) {
            arr[i - (n - k)] = nums[i];
        }
        // shift
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = arr[i];
        }
        free(arr);
    }
};
```

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

    }
};
```
