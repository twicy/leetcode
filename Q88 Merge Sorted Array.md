# Q88 Merge Sorted Array

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1;
        int i2 = n - 1;
        int counter = (int)nums1.size() - 1;

        while (i2 >= 0) {
            if (i1 >= 0 && nums1[i1] > nums2[i2]) nums1[counter--] = nums1[i1--];
            else nums1[counter--] = nums2[i2--];
        }
    }
};
```
