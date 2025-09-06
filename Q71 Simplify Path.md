# Q71 Simplify Path

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        int pos_start = 0, pos_end;
        while ((pos_end = path.find('/', pos_start)) != string::npos) {
            if (pos_end - pos_start >= 1) {
                string token = path.substr(pos_start, pos_end - pos_start);
                tokens.push_back(token);
            }
            pos_start = pos_end + 1;
        }
        if (pos_start != path.size())
            tokens.push_back(path.substr(pos_start));

        deque<string> dq;
        for (string & str: tokens) {
            if (str == ".") continue;
            if (str == "..") {
                if (!dq.empty()) dq.pop_back();
            } else {
                dq.push_back(str);
            }
        }

        string res = "/";

        while (!dq.empty()) {
            res += (dq.front() + "/");
            dq.pop_front();
        }
        if (res.size() > 1) res.pop_back();
        return res;
    }
};
```
