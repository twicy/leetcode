# Q48 Rotate Image

```cpp
class Solution {
public:
    void rotate_quad(vector<vector<int>>& matrix, int i, int j) {
        int n1 = matrix[i][j], n2 = matrix[j][matrix.size() - 1 - i];
        int n3 = matrix[matrix.size() - 1 - i][matrix.size() - 1 - j], n4 = matrix[matrix.size() - 1 - j][i];

        matrix[j][matrix.size() - 1 - i] = n1;
        matrix[matrix.size() - 1 - i][matrix.size() - 1 - j] = n2;
        matrix[matrix.size() - 1 - j][i] = n3;
        matrix[i][j] = n4;
    }
    void rotate(vector<vector<int>>& matrix) {
        int start = 0, end = matrix.size() - 1;
        while (start < end) {
            for (int j = start; j < end; j++)
                rotate_quad(matrix, start, j);
            start++;
            end--;
        }
    }
};
```
