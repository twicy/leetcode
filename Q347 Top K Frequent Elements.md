# Q347 Top K Frequent Elements

```cpp
class Solution {
public:
    class comparator{
        public:
        bool operator()(const pair<int, int> p1, const pair<int, int> p2){
            return p1.second > p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;

        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push(*it);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().first;
            pq.pop();
        }
        return result;
    }
};
```
