# Q4 Median of Two Sorted Arrays

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0, r1 = nums1.size() - 1;
        int l2 = 0, r2 = nums2.size() - 1;

        while (l1 <= r1 && l2 <= r2 && (r2 - l2 + r1 - l1 + 2) >= 3) {
            if (nums1[l1] < nums2[l2]) {
                l1++;
            } else {
                l2++;
            }
            // if used up nums1 already
            if (l1 > r1) {
                r2--;
            // else if used up nums2 already
            } else if (l2 > r2) {
                r1--;
            } else {
                if (nums1[r1] > nums2[r2]) {
                    r1--;
                } else {
                    r2--;
                }
            }
        }
        // if use up nums1
        if (l1 > r1) {
            return ((r2 - l2 + 1) % 2 == 0) ? 
                ((double)nums2[(r2 + l2) / 2] + (double)nums2[(r2 + l2 + 1) / 2]) / 2 :
                (double)nums2[(r2 + l2) / 2];
        } else if (l2 > r2) {
            return ((r1 - l1 + 1) % 2 == 0) ? 
                ((double)nums1[(r1 + l1) / 2] + (double)nums1[(r1 + l1 + 1) / 2]) / 2 :
                (double)nums1[(r1 + l1) / 2];
        } else {
            vector<int> res;
            for (int i = l1; i <= r1; i++) {
                res.push_back(nums1[i]);
            }
            for (int i = l2; i <= r2; i++) {
                res.push_back(nums2[i]);
            }
            sort(res.begin(), res.end());
            return (res.size() % 2 == 0) ?
                ((double)res[res.size() / 2] + (double)res[(res.size() - 1) / 2]) / 2 :
                (double)res[res.size() / 2];
        }
        return 0.0f;
    }
};
```
