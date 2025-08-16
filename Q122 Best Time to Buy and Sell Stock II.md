# Q122 Best Time to Buy and Sell Stock II

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int i = 0;
        for (i = 0; i < prices.size() - 1; i++) {
            if (prices[i + 1] <= prices[i]) {
                continue;
            }
            break;
        }
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i + 1] > prices[i]) {
                res += (prices[i + 1] - prices[i]);
                i++;
            }
            while (i < prices.size() - 1 && prices[i + 1] <= prices[i]) i++;
        }
        return res;
    }
};
```
