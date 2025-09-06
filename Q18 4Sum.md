# Q18 4Sum

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int num1 = 0; num1 < (int)nums.size() - 3; num1++) {
            while (num1 != 0 && num1 < (int)nums.size() - 3 && nums[num1] == nums[num1 - 1]) {num1++;}
            for (int num2 = num1 + 1; num2 < (int)nums.size() - 2; num2++) {
                while (num2 != num1 + 1 && num2 < (int)nums.size() - 2 && nums[num2] == nums[num2 - 1]) {num2++;}
                int first_two_sum = nums[num1] + nums[num2];
                int num3 = num2 + 1;
                int num4 = nums.size() - 1;
                while (num3 < num4) {
                    long long sum = (long long)first_two_sum + (long long)nums[num3] + (long long)nums[num4];
                    if (sum > target) {
                        num4--;
                    } else if (sum < target) {
                        num3++;
                    } else {
                        res.push_back(vector<int>{nums[num1], nums[num2], nums[num3], nums[num4]});
                        while (num3 < num4 && nums[num3] == nums[num3 + 1]) {num3++;}
                        while (num3 < num4 && nums[num4] == nums[num4 - 1]) {num4--;}
                        num3++;
                        num4--;
                    }
                }
            }
        }
        return res;
    }
};
```
