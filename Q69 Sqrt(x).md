# Q69 Sqrt(x)

```cpp
class Solution {
public:
    // x_{n + 1} = x_{n} - f(x_{n}) / f'(x_{n})
    // f(x) = x^2 - c, f'(x) = 2x
    int mySqrt(int constant) {
        if (constant == 0 || constant == 1) return constant;
        double curr_ans = constant / 2.0;
        const double eps = 1e-7;

        while (true) {
            double next_ans = curr_ans - (curr_ans * curr_ans - constant) / (2 * curr_ans);
            if (fabs(next_ans - curr_ans) < eps) {
                curr_ans = next_ans;
                break;
            }
            curr_ans = next_ans;
        }
        return static_cast<int>(std::floor(curr_ans));
    }
};

```
