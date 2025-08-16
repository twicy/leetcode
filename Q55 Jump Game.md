# Q55 Jump Game

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        int farthest = 0;
        int farthest_index = 0;
        while (index < nums.size() - 1) {
            farthest = index;
            for (int step = 1; step <= nums[index]; step++) {
                int next_index = index + step;
                if (next_index >= nums.size() - 1) return true;
                if (next_index + nums[next_index] > farthest) {
                    farthest = next_index + nums[next_index];
                    farthest_index = next_index;
                }
            }
            if (farthest == index) return false;
            index = farthest_index;
        }
        return true;
    }
};
```

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i <= cover; i++) {
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true;
        }
        return false;
    }
};
```
