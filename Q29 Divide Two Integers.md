# Q29 Divide Two Integers

```cpp
class Solution {
public:
    int divide(long dividend, long divisor) {
        if(divisor == dividend) return 1;
        long ans = 0;
        int sign = 1;
        if(dividend < 0 && divisor > 0) sign = -1;
        if(dividend > 0 && divisor < 0) sign = -1;
        divisor = abs(divisor);
        dividend = abs(dividend);
        while(divisor <= dividend){
            long count = 0;
            while((divisor << (count + 1)) < dividend) count++;
            dividend -= divisor << count;
            ans += 1 << count;
        }
        if(sign < 0 && -ans < INT_MIN) return INT_MIN;
        if(sign > 0 && ans > INT_MAX) return INT_MAX;
        return sign > 0 ? ans:-ans;
    }
};
```
