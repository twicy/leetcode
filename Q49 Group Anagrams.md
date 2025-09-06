# Q49 Group Anagrams

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<string> v;
        for(string x:strs){
            string temp = x;
            sort(temp.begin(),temp.end());
            mp[temp].push_back (x);
        }

        vector<vector<string>> ans;
        for(const auto& vv : mp){
            ans.push_back(vv.second);
        }

        return ans;
    }
};
```
