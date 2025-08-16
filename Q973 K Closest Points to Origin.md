# Q973 K Closest Points to Origin

```cpp
class Solution {
    struct edge {
        int x;
        int y;
        long len;
    };
    struct comparator {
        bool operator()(struct edge &edge1, struct edge &edge2)const {
            return (edge1.len > edge2.len);
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<struct edge, vector<struct edge>, comparator> pq;

        for (auto point : points) {
            pq.push({point[0], point[1], point[0] * point[0] + point[1] * point[1]});
        }

        while (!pq.empty() && k--) {
            res.push_back({pq.top().x, pq.top().y});
            pq.pop();
        }
        return res;
    }
};
```
