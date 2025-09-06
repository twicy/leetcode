# Q1636 Sort Array by Increasing Frequency

```cpp
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int freq[201] = {0};
        for (int i = 0; i < (int)nums.size(); i++) {
            freq[nums[i] + 100]++;
        }
        auto comp = [&](const int x, const int y)->bool {
            if (freq[x + 100] == freq[y + 100]) return (x > y);
            return (freq[x + 100] < freq[y + 100]);
        };
        sort(nums.begin(), nums.end(), comp);
        return nums;
    }
};
```
