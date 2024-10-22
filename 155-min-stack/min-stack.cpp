class MinStack {
public:
    int mn;
    vector<int> a;
    vector<int> mnArr;
    MinStack() {}

    void push(int val) {
        a.push_back(val);
        if (mnArr.empty())
            mnArr.push_back(val);
        else
            mnArr.push_back(min(mnArr.back(), val));
    }

    void pop() {
        if (!a.empty()) {
            a.pop_back();
            mnArr.pop_back();
        }
    }

    int top() { return a.back(); }

    int getMin() { return mnArr.back(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */