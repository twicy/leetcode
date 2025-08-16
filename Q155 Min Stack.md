# Q155 Min Stack

```cpp
class MinStack {
    vector<vector<int> > stk;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push_back({val, val});
            return;
        } else {
            stk.push_back({val, min(val, getMin())});
        }
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        if (stk.empty()) return -1;
        return stk.back()[0];
    }
    
    int getMin() {
        if (stk.empty()) return -1;
        return stk.back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
