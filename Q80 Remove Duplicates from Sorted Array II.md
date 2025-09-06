# Q80 Remove Duplicates from Sorted Array II

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++) {
            int internal_counter = 1;
            while (i < (int)nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
                internal_counter++;
            }
            if (internal_counter >= 2) internal_counter = 2;
            for (int j = 0; j < internal_counter; j++) {
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
};
```
