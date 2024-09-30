class CustomStack {
public:
    int mx;
    vector<int> p;
    CustomStack(int maxSize) { mx = maxSize; }

    void push(int x) {if(p.size()==mx)return; p.push_back(x); }

    int pop() {
        if(p.size()==0)
        return -1;
        int x = p.back();
        p.pop_back();
        return x;
    }

    void increment(int k, int val) {
        for (int i = 0; i < min((int)p.size(),k); i++) {
            p[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */