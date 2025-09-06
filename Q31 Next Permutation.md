# Q31 Next Permutation

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = (int)nums.size() - 1;
        while (i >= 1 && nums[i - 1] > nums[i]) {
            i--;
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = nums.size() - 1;
        while (j >= i && nums[j] < nums[i - 1]) {
            j--;
        }

        cout << i << " " << j << endl;
        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};
```
