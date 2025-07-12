# Q941 Valid Mountain Array

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool ascending = true;

        if (arr.size() < 3) {
            return false;
        }
        if (arr[0] >= arr[1]) {
            return false;
        }

        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                if (ascending) {
                    continue;
                } else {
                    return false;
                }
            } else if (arr[i] > arr[i + 1]) {
                if (ascending) {
                    ascending = false;
                } else {
                    continue;
                }
            } else {
                return false;
            }
        }
        return !ascending;
    }
};
```

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0;

        if (arr.size() < 3) {
            return false;
        }

        while ((i != arr.size() - 1) && arr[i] < arr[i + 1]) {
            i++;
        }
        if (i == arr.size() - 1 || i == 0) {
            return false;
        }
        while ((i != arr.size() - 1) && arr[i] > arr[i + 1]) {
            i++;
        }
        return (i == arr.size() - 1);
    }
};
```
