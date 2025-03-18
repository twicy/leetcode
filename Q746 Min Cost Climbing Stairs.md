# Q746 Min Cost Climbing Stairs

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> res(cost.size() + 1, 0);

        res[0] = cost[0];
        res[1] = cost[1];

        cost.push_back(0);
        for (int i = 2; i < res.size(); i++) {
            res[i] = min(res[i - 1], res[i - 2]) + cost[i];
        }
        cost.pop_back();
        return res.back();
    }
};
```
