# Q51 N-Queens

```cpp
class Solution {
    vector<vector<string>> res;

    void backtrack(vector<string>& curr, vector<bool> &cols, vector<bool>& diag, vector<bool>& adiag, int n, int row) {
        if (row == n) {
            res.push_back(curr);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag[row - col + n - 1] || adiag[row + col]) continue;
            curr[row][col] = 'Q';
            cols[col] = true;
            diag[row - col + n - 1] = true;
            adiag[row + col] = true;
            backtrack(curr, cols, diag, adiag, n, row + 1);
            adiag[row + col] = false;
            diag[row - col + n - 1] = false;
            cols[col] = false;
            curr[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> curr(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag(2 * n - 1, false);
        vector<bool> adiag(2 * n - 1, false);
        backtrack(curr, cols, diag, adiag, n, 0);
        return res;
    }
};
```
