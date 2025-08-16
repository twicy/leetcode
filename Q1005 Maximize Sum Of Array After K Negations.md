# Q1005 Maximize Sum Of Array After K Negations

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; i++) {
            int smallest = pq.top();
            pq.pop();
            pq.push(-smallest);
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};
```
