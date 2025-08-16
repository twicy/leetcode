# Q860 Lemonade Change

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[3] = {0};
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                arr[0]++;
            } else if (bills[i] == 10) {
                arr[1]++;
                if (arr[0] == 0) return false;
                arr[0]--;
            } else {
                arr[2]++;
                if (arr[1] == 0) {
                    if (arr[0] < 3) return false;
                    arr[0]-=3;
                } else {
                    if (arr[0] == 0) return false;
                    arr[1]--;
                    arr[0]--;
                }
            }
        }
        return true;
    }
};
```
