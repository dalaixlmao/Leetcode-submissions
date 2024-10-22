class Solution {
public:
    bool checkOperator(string s) {
        return s == "+" || s == "*" || s == "-" || s == "/";
    }

    int calc(int x, int y, char op) {
        switch (op) {
        case '+':
            return y + x;
        case '-':
            return y - x;
        case '*':
            return y * x;
        case '/':
            return y / x;
        }
        return x + y;
    }

    int evalRPN(vector<string>& st) {
        stack<int> s;
        int n = st.size();
        for (int i = 0; i < n; i++) {
            if (checkOperator(st[i])) {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(calc(x, y, st[i][0]));
            }
            else{
                s.push(stoi(st[i]));
            }
        }
        return s.top();
    }
};