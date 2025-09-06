# Q56 Merge Intervals

Not very efficient

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (const vector<int> a, const vector<int> b) {
            if (a[0] == b[0]) {
                return (a[1] > b[1]);
            }
            return (a[0] < b[0]);
        });
        vector<vector<int>> res;
        int curr_left = intervals[0][0], curr_right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (curr_right >= intervals[i][1]) continue;
            if (curr_right >= intervals[i][0]) {
                curr_right = intervals[i][1];
                continue;
            }
            res.push_back({curr_left, curr_right});
            curr_left = intervals[i][0];
            curr_right = intervals[i][1];
        }
        res.push_back({curr_left, curr_right});
        return res;
    }
};
```

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int index = 1; index < intervals.size(); index++) {
            if(res.back()[1] >= intervals[index][0]) {
                res.back()[1] = max(res.back()[1], intervals[index][1]);
            }
            else {
                res.push_back(intervals[index]);
            }
        }
        return res;
    }
};
```
