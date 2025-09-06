# Q84 Largest Rectangle in Histogram

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        int result = 0;
        for (int i = 1; i < heights.size(); i++) {
            while (heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int w = i - st.top() - 1;
                int h = heights[mid];
                result = max(result, w * h);
            }
            st.push(i);
        }
        return result;
    }
};
```

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(), 0);
        vector<int> right(heights.size(), 0);
        stack<int> stk;

        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = (stk.empty()) ? -1: stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right[i] = (stk.empty()) ? heights.size(): stk.top();
            stk.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};
```
