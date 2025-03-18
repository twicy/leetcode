# Q216 Combination Sum III

```cpp
class Solution {
    vector<vector<int>> res;
    void backtrack(int start, int k, int n, vector<int> &curr){
        if (n < 0) {
            return;
        }
        if (curr.size() == k) {
            if (n == 0) {
                res.push_back(curr);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            backtrack(i + 1, k, n - i, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(1, k, n, curr);
        return res;
    }
};
```
